#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i < (n); i++)
using namespace std;
using ll = long long;

int main(){
    int N; cin>>N;
    string S; cin>>S;
    
    //各文字の累積和
    vector<int> Rv(N),Gv(N),Bv(N);
    int R=0,G=0,B=0;
    rep(i,N){
        if(S[i]=='R') R++;
        if(S[i]=='G') G++;
        if(S[i]=='B') B++;
        Rv[i]=R; Gv[i]=G; Bv[i]=B;
    }
    
    // for(int x:Bv){
    //     cout << x << " ";
    // }
    
    ll ans=0;
    for(int i=0; i<N-2; i++){
        for(int j=i+1; j<N-1; j++){
            if(S[i]==S[j]) continue;
            
            if((S[i]=='R' && S[j] =='G') || (S[j]=='R' && S[i] =='G')){
                ans += Bv[N-1] -Bv[j];
                if(2*j-i < N && S[2*j-i]=='B') ans--;
            }
            if((S[i]=='R' && S[j] =='B') || (S[j]=='R' && S[i] =='B')){
                ans += Gv[N-1] -Gv[j];
                if(2*j-i < N && S[2*j-i]=='G') ans--;
            }
            if((S[i]=='G' && S[j] =='B') || (S[j]=='G' && S[i] =='B')){
                ans += Rv[N-1] -Rv[j];
                if(2*j-i < N && S[2*j-i]=='R') ans--;
            }
        
        }
    }
    
    cout << ans << endl;
}
