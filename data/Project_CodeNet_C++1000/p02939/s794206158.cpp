#include <bits/stdc++.h>
using namespace std;

template<class T>
bool chmax(T &a, const T &b){
    if(a < b){
        a = b;
        return 1;
    }
    
    return 0;
    
}


int main(void){
    
    string S;
    cin >> S;

  
    int DP[S.size()+1][3];
    memset(DP, 0, sizeof(DP));
    DP[1][0] = 1;
    DP[2][1] = 1;
    
    for(int i = 0; i <= S.size();i++){
        if(i >= 1 && S[i-1] != S[i]) chmax(DP[i+1][1],DP[i][1]+1);
        if((i >= 2 && S[i-2] != S[i] )|| S[i-1] != S[i+1]) chmax(DP[i+2][2],DP[i][2]+1);
        chmax(DP[i+2][2],DP[i][1]+1);
        chmax(DP[i+1][1],DP[i][2]+1);
    }
    
    cout <<max(DP[S.size()][1],DP[S.size()][2]) <<endl;
    
    
}
