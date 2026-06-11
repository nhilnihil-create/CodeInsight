#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define INF 1e9+7
#define rep(i,n) for(ll i=0;i<n;i++)
#define pii pair<int,int>
#define pll pair<ll,ll>
const int maxn = 100;
ll mod = INF;

int n;
int b[maxn];
int ans=0;

int main(){
    cin >> n;
    rep(i,n-1)cin >> b[i];
    rep(i,n){
        if(i==0)ans+=b[0];
        else if(i==n-1)ans+=b[n-2];
        else ans+=min(b[i],b[i-1]);
    }
    cout << ans<<endl;
    return 0;
}