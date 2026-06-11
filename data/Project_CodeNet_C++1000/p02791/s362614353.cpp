#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define INF 1e9+7
#define rep(i,n) for(ll i=0;i<n;i++)
#define pii pair<int,int>
#define pll pair<ll,ll>
const int maxn = 200000;
ll mod = INF;


int main(){
    int n;
    int ans=0;
    int m=INF;
    cin >> n;
    rep(i,n){
        int t;cin >> t;
        m=min(m,t);
        if(m>=t){
            ans++;
        }
    }

    cout << ans<<endl;
    return 0;
}