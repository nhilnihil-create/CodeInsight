#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define INF 1e9+7
#define rep(i,n) for(ll i=0;i<n;i++)
#define pii pair<int,int>
#define pll pair<ll,ll>
const int maxn = 1000000;
ll mod = INF;


int main(){
    int n;
    ll ans=0;
    ll cnt[10][10]={0};

    cin >> n;
    int k=1;
    for(int i=1;i<=n;i++){
        if(k*10<=i)k=k*10;
        cnt[i/k][i%10]++;
    }

    for(int i=1;i<=9;i++){
        for(int j=1;j<=9;j++){
            ans+=cnt[i][j]*cnt[j][i];
        }
    }

    cout << ans<<endl;
    return 0;
}