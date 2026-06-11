#include<iostream>
#include<vector>
#include<stdio.h>
using namespace std;
#define DUMP(x)  cerr << #x << " = " << (x) << endl;
#define DEBUG(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;

vector<vector<int> > matrix;


int main(){
    int H;
    while(cin>>H && H>0){
        if(H==0)
            break;
        vector<int> temp(5,0);
        matrix.push_back(temp);
        for (int i = 0; i < H; i++) {
            vector<int> temp(5,0);
            for (int j = 0; j < 5; j++)
                cin >> temp[j];
            matrix.push_back(temp);
        }

        bool flag = true;
        int score = 0;


        while(flag){
            // for (int i = 0; i < H; i++) {                                                                                                                           
            //  for (int j=0; j < 5; j++)                                                                                                                              
            //      cout << matrix[i][j];                                                                                                                              
            //  cout << endl;                                                                                                                                          
            // }                                                                                                                                                       
            // ?¶????????????¨????????¢??????                                                                                                                                    
            // ?¶?????????????-1?????£??\                                                                                                                                      
            flag = false;
            for (int i=0; i < H+1; i++) {
                int count = 1, num=-1 ,start = 0;
                bool delete_flag = false;
                for (int j=0; j <3 ; j++) {
                    if(matrix[i][j]!=-1 &&
                       matrix[i][j]!=0 &&
                       matrix[i][j]==matrix[i][j+1] &&
                       matrix[i][j+1]==matrix[i][j+2]){
                        delete_flag = true;
                        num = matrix[i][j];
                        start = j;
                        break;
                    }
                }
                if(delete_flag){
                    for (int j=start; j < 5; j++) {
                        if(matrix[i][j]==num){
                            score += num;
                            matrix[i][j] = -1;
                            // if(j != 4 && matrix[i][j+1] != matrix[i][j])                                                                                            
                            //  break;                                                                                                                                 
                        }else{break;}
                    }
                }
            }

            // ???????????????????¢????                                                                                                                                        
            // ???????????????????????????0?????£??\                                                                                                                               
            bool fail_flag = true;
            while(fail_flag){
                fail_flag = false;
                for (int i=H; i > 0; i--) {
                    for (int j=0; j < 5; j++) {
                        if(matrix[i][j]==-1){
                            fail_flag = true;
                            flag = true;
                            if(matrix[i-1][j]!=0){
                                matrix[i][j] = matrix[i-1][j];
                                matrix[i-1][j] = -1;
                            }
                            else
                                matrix[i][j] = 0;
                        }
                    }
                }
                for (int j=0; j < 5; j++)
                    matrix[0][j] = 0;
            }
        }
        cout << score << endl;
        matrix.clear();
    }
    return 0;
}