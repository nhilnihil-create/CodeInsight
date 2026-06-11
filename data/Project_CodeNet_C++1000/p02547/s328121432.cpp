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

int di1, di2;
int n;


int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int s = 0;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> di1 >> di2;
        s += (di1 == di2 ? 1 : -s);
        if(s == 3)
            return cout << "Yes" << endl, 0;
    }
    cout << "No" << endl;
	return 0;
}
