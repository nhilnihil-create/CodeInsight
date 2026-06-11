#include <bits/stdc++.h>

const int INF = 1e9;
const int MOD = 1e9 + 7;

using namespace std;

typedef long long ll;

#define REP(i, n) for (int i = 0; i < int(n); i++)
#define REPD(i, n) for (int i = n - 1; i >= 0; i--)
#define FOR(i, a, b) for (int i = a; i < int(b); i++)
#define FORD(i, a, b) for (int i = b - 1; i >= int(a); i--)
#define WRAP(y, x, h, w) (0 <= y && y < h && 0 <= x && x < w)

#define ALL(x) (x).begin(), (x).end()

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main()
{
    ll n;
    cin >> n;
    if(n==2){
        cout<<1<<endl;
        return 0;
    }
    int ans=2;
    for (ll i = 2; i * i <= n; i++) {
        if(n%i==0){
            ll n2=n;
            while(n2%i==0){
                n2/=i;
            }
            if(n2%i==1)
            ans++;
        }
    }
    for(ll i=2;i*i<=n-1;i++){
        if((n-1)%i==0){
            if(i*i==n-1)
            ans++;
            else
            ans+=2;
        }
    }
    cout<<ans<<endl;
}