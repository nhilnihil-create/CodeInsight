#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1000000007;
#define INF 1LL<<30
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()


int main(){
    int n;
    string s;
    cin>>n>>s;

    vector<ll> r(n,0),g(n,0),b(n,0);
    rep(i,n){
        if(s[i]=='R') r[i]=1;
        else if(s[i]=='G') g[i]=1;
        else b[i]=1;
    }
    vector<ll> sr(n+1,0),sg(n+1,0),sb(n+1,0);
    rep(i,n){
        sr[i+1]=sr[i]+r[i];
        sg[i+1]=sg[i]+g[i];
        sb[i+1]=sb[i]+b[i];
    }

    ll ans=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if((s[i]=='R' && s[j]=='G') || (s[i]=='G' && s[j]=='R')){
                ans+=sb[n]-sb[j];
                if(2*j-i>=n) continue;
                if(s[2*j-i]=='B') ans--;                
            }
            else if((s[i]=='R' && s[j]=='B') || (s[i]=='B' && s[j]=='R')){
                ans+=sg[n]-sg[j];
                if(2*j-i>=n) continue;
                if(s[2*j-i]=='G') ans--;                
            }
            else if((s[i]=='G' && s[j]=='B') || (s[i]=='B' && s[j]=='G')){
                ans+=sr[n]-sr[j];
                if(2*j-i>=n) continue;
                if(s[2*j-i]=='R') ans--;                
            }
        }
    }
    
    cout<<ans<<endl;
}

