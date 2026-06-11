#include<iostream>
#include<algorithm>
#include<math.h>
#include<vector>
#define rep(i,N) for(int i=0; i<N; i++)
using namespace std;


int main(){
    string S,T;
    cin >> S >> T;
    int min = 2000;
    rep(i,S.size()-T.size()+1){
        int cnt = 0;
        rep(j,T.size()){
            if(S[i+j]==T[j]){
                continue;
            }else{
                cnt++;
            }
        }
        if(cnt < min){
            min = cnt;
        }

    }
    cout << min << endl;
    
}