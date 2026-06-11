#include <bits/stdc++.h>
#include <climits>
#include <sstream>
using namespace std;

int main(){

    string S;
    cin >> S;
    int N = S.size();
    vector<int> ans(N,1);
    
    for(int i = 0; i < N-1;i++){
        if(S[i]=='R' && S[i+1]=='R'){
            ans[i+2] += ans[i];
            ans[i] = 0;
        }
    }
    
    for(int i = N-1; i > 0;i--){
        if(S[i]=='L' && S[i-1]=='L'){
            ans[i-2] += ans[i];
            ans[i] = 0;
        }
    }   
    
    for(int i = 0; i < N;i++){
        cout << ans[i];
        if(i != N)cout <<" ";
        else cout << endl;
    }
    return 0;
    
}