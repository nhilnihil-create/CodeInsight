#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define INF 1e9+7
#define rep(i,n) for(ll i=0;i<n;i++)
#define pii pair<int,int>
#define pll pair<ll,ll>
const int maxn = 1000000;
ll mod = INF;

ll h;
ll cnt=1;
ll ans=0;

int main(){
    cin >> h;
    
    while(h>0){
        ans+=cnt;
        h=h/2;
        cnt=cnt*2;
    }

    cout << ans<<endl;
    
    return 0;
}