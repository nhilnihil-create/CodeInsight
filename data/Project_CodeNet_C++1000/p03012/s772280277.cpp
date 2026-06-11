//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pp pair<int,int>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define ld long double
#define al(a) (a).begin(),(a).end()
#define mk make_pair
#define check cout<<"?"<<endl;

ll MOD=1000000007;
ll mod=998244353;
int inf=1000001000;
ll INF=1e18+5;

int main(){
    int n,ans=inf; cin>>n;
    vector<int> w(n,0),sum(n+1,0);
    rep(i,n){
        cin>>w[i];
        sum[i+1]=sum[i]+w[i];
    }
    rep(i,n) ans=min(ans,abs(sum[n]-2*sum[i]));
    cout<<ans<<endl;
}
