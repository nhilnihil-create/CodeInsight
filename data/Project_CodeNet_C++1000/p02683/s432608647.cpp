#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
 
#define all(x)                      (x).begin(),(x).end()
#define X                           first
#define Y                           second
#define sep                         ' '
#define endl                        '\n'
#define debug(x)                    cerr << #x << ": " <<  x << endl;
#define alog(a, n)                  for (int i = 0; i < n; i++) cout << a[i] << " "; cout << endl;
 
ll poww(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}
 
const ll MAXN = 1e6 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

int n, m, x;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m >> x;
    vector <vector <int> > a(n, vector <int>(m) );
    int c[n];
    for(int i = 0; i < n; i++){
        cin >> c[i];
        for(int j = 0; j < m; j++) cin >> a[i][j];
    }
    int mask = 1 << n;
    ll mn = INF;
    for(int sub = 0; sub < mask; sub++){
        vector <int> level(m, 0);
        ll temp = 0;
        for(int j = 0; j < n; j++){
            if(!(sub & (1 << j)))
                continue;
            temp += c[j];
            for(int k = 0; k < m; k++)
                level[k] += a[j][k];
        }
        bool flag = false;
        for(int j = 0; j < m; j++)
            if(level[j] < x)
            {flag = true; break;}
        if(flag)
            continue;
        mn = min(mn, temp);
    }
    cout << (mn == INF ? -1 : mn)  << endl;
	return 0;
}
