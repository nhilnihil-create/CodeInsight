#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1000000007;
#define INF 1LL<<30
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()

int main(){
    int n,K,R,S,P;
    string t;
    cin>>n>>K>>R>>S>>P>>t;

    ll ans=0;
    rep(k,K){
        bool last=false;
        for(int i=k;i<n;i+=K){
            if(i>=K && t[i-K]==t[i] && last) last=false;
            else{
                last=true;
                if(t[i]=='r') ans+=P;
                else if(t[i]=='s') ans+=R;
                else ans+=S;
            }
        }
    }

    cout<<ans<<endl;
}

