#include <bits/stdc++.h>

using namespace std;
int bingo[13];
int main()
{
    int arr[4][4];
    int b[112];
    memset(b,-1,sizeof(int)*112);
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cin >> arr[i][j];
            b[arr[i][j]] = i*3+j;
        }
    }
    int n;
    cin >> n;
    int t=0;
    for(int i=0;i<n;i++){
        int a;
        cin >> a;
        if(b[a]>-1){
            bingo[b[a]]=1;
            t++;
        }
    }
   
    if(t>=3){
       for(int i=0;i<9;i+=3){
           if(bingo[i] == bingo[i+1] && bingo[i+1]==bingo[i+2] && bingo[i]){
               cout << "Yes" << endl;
                return 0;
           }
       }
       for(int i =0;i<3;i+=1){
           if (bingo[i] == bingo[i + 3] && bingo[i + 3] == bingo[i + 6] && bingo[i])
           {
               cout << "Yes" << endl;
               return 0;
           }
       }
       if(((bingo[0] == bingo[4] && bingo[4] == bingo[8] && bingo[0]) || (bingo[2] == bingo[4] && bingo[4] == bingo[6] && bingo[2]))){
           cout << "Yes" << endl;
           return 0;
       }
       cout << "No" << endl;
    }
    else{
        cout << "No" << endl;
    }


    return 0;
}