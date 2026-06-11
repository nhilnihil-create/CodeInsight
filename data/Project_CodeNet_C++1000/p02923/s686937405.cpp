#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define INF 1e9+7
#define rep(i,n) for(ll i=0;i<n;i++)
#define pii pair<int,int>
#define pll pair<ll,ll>
const int maxn = 100000;
ll mod = INF;

int n;
int h[maxn];

int main(){
    cin >> n;
    rep(i,n)cin >> h[i];
    int ans=0;
    int streak=0;
    for(int i=0;i<n-1;i++){
        if(h[i]>=h[i+1]){
            streak++;
        }else{
            ans=max(ans,streak);
            streak=0;
        }
        if(i==n-2)ans=max(ans,streak);
    }

    cout << ans<<endl;

    return 0;
}