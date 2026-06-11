#include <bits/stdc++.h>
using namespace std;
//型名省略
typedef long long ll;
typedef vector<long long> vl;
typedef vector<vector<long long>> vll;
typedef vector<char> vc;
typedef vector<vector<char>> vcc;
typedef vector<string> vs;
//マクロ
#define rep(i,n) for(ll i = 0; i < (ll) n; i++)
#define rep2(i,x,n) for(ll i = (ll) x; i < (ll) n; i++)
#define all(A) A.begin(), A.end()
//正誤判定
void Yes(bool ans){cout << (ans? "Yes" : "No") << endl;}
void YES(bool ans){cout << (ans? "YES" : "NO") << endl;}

int main() {
    ll a,b,c,k; cin >> a >> b >> c >> k;

    if(k <= a) cout << k << endl;
    else if(k <= a + b)cout << a << endl;
    else cout << a - (k - (a + b)) << endl;
}