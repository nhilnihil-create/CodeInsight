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
    int n,ans=inf,cur; cin>>n;
    vector<int> x(n,0);
    rep(i,n) cin>>x[i];
    for(int i=1;i<=100;i++){
        cur=0;
        rep(j,n) cur+=(x[j]-i)*(x[j]-i);
        ans=min(ans,cur);
    }
    cout<<ans<<endl;
}