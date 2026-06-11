#include <bits/stdc++.h>

using namespace std;

#define fastio cin.tie(NULL);cout.tie(NULL);ios_base::sync_with_stdio(0);
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define MAXN 200005
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f
#define MOD 1000000007
#define pb push_back
#define endl '\n'
#define int long long

typedef long long ll;
typedef pair <int, int> pii;
typedef vector <int> vi;
typedef vector <pii> vii;
typedef vector <vi> matriz;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// auto timer_start = chrono::steady_clock::now().time_since_epoch().count();

int a, b, c, n, m, k;
string s, t, u;

int32_t main(){
    fastio
    cin >> s;
    if(s == "Sunny") cout << "Cloudy";
    else if(s == "Cloudy") cout << "Rainy";
    else cout << "Sunny";
    cout << endl;

    return 0;
}