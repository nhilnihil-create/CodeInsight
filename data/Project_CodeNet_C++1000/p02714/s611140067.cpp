#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i < (n); i++)
using namespace std;
using ll = long long;

int main(){
    int N; cin>>N;
    string S; cin>>S;
    
    //各文字の個数
    ll R=0,G=0,B=0;
    rep(i,N){
        if(S[i]=='R') R++;
        if(S[i]=='G') G++;
        if(S[i]=='B') B++;
    }
    
    ll ans = R*G*B;
    
    for(int i=0; i<N-2; i++){
        for(int j=i; j<N-1; j++){
            if(2*j-i>=N) break;
            if((S[i]!=S[j]) && (S[i]!=S[2*j-i]) && (S[j]!=S[2*j-i])){
                ans--;
            }
        }
    }
    
    cout << ans << endl;
}
