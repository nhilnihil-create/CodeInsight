#include <bits/stdc++.h>
#define ll long long
#define rep(i,a,b) for(long long i=a; i<b; i+=1)
#define repr(i,a,b) for(long long i=a; i<=b; i+=1)
#define vec vector<ll>
#define map map<char,int>
#define repa(p,A) for(auto p:A)
#define pb push_back
#define sort(a) sort(a.begin(),a.end())
#define reverse(a) reverse(a.begin(),a.end())
const double PI=acos(-1);
using namespace std;

int main( ) {
    ll H,W,K;
    cin>>H>>W>>K;
    vector<string> S(H);
    rep(i,0,H) cin>>S[i];
    ll ans=0;
    rep(i,0,1<<H) {
        rep(j,0,1<<W) {
            ll count=0;
            rep(x,0,H) {
                rep(y,0,W) {
                    if(i>>x &1) continue;
                    if(j>>y &1) continue;
                    if(S[x][y]=='#') count+=1;
                }  
                
            }
            if(count==K) ans+=1;
        }
        
    }
    cout<<ans<<endl;
}