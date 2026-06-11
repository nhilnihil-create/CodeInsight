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

int main() {
    int n,k,ans; cin>>n>>k;
    if(k>(n-1)*(n-2)/2) ans=-1;
    else ans=n*(n-1)/2-k;
    cout<<ans<<endl;
    if(ans!=-1){
        rep(i,n-1) cout<<i+1<<" "<<n<<endl;
        int cnt=n-1;
        for(int i=1;i<=n-2;i++){
            for(int j=i+1;j<=n-1;j++){
                if(cnt==ans){
                  i=n; break;
                }
                cout<<i<<" "<<j<<endl;
                cnt++;
            }
        }
    }
}