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
int x[maxn];
int ans=INF;

int main(){
    cin >> n;
    rep(i,n)cin >> x[i];
    for(int i=1;i<=100;i++){
        int c=i;
        int temp=0;
        rep(j,n){
            temp+=(x[j]-c)*(x[j]-c);
        }
        ans=min(ans,temp);
    }
    cout << ans<<endl;
    return 0;
}