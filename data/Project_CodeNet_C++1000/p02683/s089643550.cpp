#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
#define _USE_MATH_DEFINES
#include <math.h>
#define rep(i,n) for(int i = 0;i < n;i++)
#define NIL = -1;
#define all(x) x.begin(),x.end()
const ll INF = 1e9;
const ll mod = 1e9 + 7;

int digit(ll x) {
    if (x / 10 == 0) return 1;
    return digit(x / 10) + 1;
}

ll gcd(long long a,long long b) {
    if (a < b) swap(a,b);
    if (b == 0) return a;
    
    return gcd(b,a%b);
}

ll lcm(ll a,ll b){
    return ((a * b == 0)) ? 0 : (a / gcd(a,b) * b);
}

double DegreeToRadian(double degree){
    return degree * M_PI / 180.0;
}

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};


/////////////////////////////////////////////////////////////////////////////////////

int main(){
    int n,m, x;
    cin >> n >> m >> x;
    vector<int> c(n);
    vector<vector<int>> a(n, vector<int>(m));
    int point[13];
    bool ok[13];

    for (int i = 0;i < n;i++){
        cin >> c[i];
        for (int j = 0;j < m;j++){
            cin >> a[i][j];
        }
    }
    bool solve = true;
    bool can = false;
    ll ans = 1e9;
    int cnt;
    for (int bit = 0;bit < (1 << n);bit++){
        memset(ok, false, sizeof(ok));
        memset(point, 0, sizeof(point));
        ll pay = 0;
        solve = true;
        for (int i = 0;i < n;i++){
            if (bit & (1 << i)){
                pay += c[i];
                for (int j = 0;j < m;j++){
                    point[j] += a[i][j];
                    if (point[j] >= x){
                        ok[j] = true;
                    }
                }
            }
        }   
        for (int i = 0;i < m;i++){
            if (ok[i] == false){
                solve = false;
                break;
            }
        }

        if (solve){
            can = true;
            ans = min(ans, pay);
        }
    }

    if (can == false){
        cout << -1 << endl;
    }
    else{
        cout << ans << endl;
    }
}