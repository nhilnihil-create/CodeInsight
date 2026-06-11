#include <iostream>
#include <iomanip>
using namespace std;

int main(void){
        int i,j,x,y,s,before,after,max;
        int before1,before2,after1,after2;

        while(1){
                max = 0;
                cin >> x >> y >> s;
                if(x == 0 && y == 0 && s == 0){ 
                        break;
                }   

                for(i = 1; i < s; i++){
                        for(j = 1; j < s; j++){
                                before1 = i * (100 + x);
                                before2 = j * (100 + x);
                                before1 = before1 / 100;
                                before2 = before2 / 100;
                                before = before1 + before2;

                                if(before == s){
                                        after1 = i * (100 + y);
                                        after2 = j * (100 + y);
                                        after1 = after1 / 100;
                                        after2 = after2 / 100;
                                        after = after1 + after2;
                                        if(after > max){
                                                max = after;
                                        }   
                                }   
                        }   
                }   
                cout << max << endl;
        }   
        return 0;
}