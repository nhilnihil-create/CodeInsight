// Made by Luis Miguel Baez
// es.luismiguelbaez@gmail.com
 
#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define precise(n,k) fixed << setprecision(k) << n
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
 
#define uint  unsigned int
#define ll    long long
#define ull   unsigned long long
#define ld    long double
 
#define pii   pair<int, int>
#define piii  pair<int, pair<int, int>>
#define pll   pair<ll, ll>
 
#define F  first
#define S  second
#define PB push_back
#define MP make_pair
 
#define debug(...) "[" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
 
string to_string(string s) {
    return '"' + s + '"';
}
 
string to_string(bool b) {
    return (b ? "true" : "false");
}
 
template <typename A, typename B>
string to_string(pair<A, B> p) {
    return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
 
template <typename A, typename T>
string to_string(A v) {
    bool first = true;
    string res = "{";
    for (const T &x : v) {
        if (!first) {
            res += ", ";
        }
        first = false;
        res += to_string((T)x);
    }
    res += "}";
    return res;
}
 
// add templates here

template<class T>
void println(const vector<T> &data) {
    cout << to_string<vector<T>, T>(data) <<endl;
}
 
template<class T>
void println(const T &data) {
    cout << to_string((T)data) << endl;
}
 
const int MOD = int(1e9+7);
const int oo  = int(1e9 + 20);
const ll lloo  = (ll)(1e18 + 10);

void solve() {
    ll A, B, C, D;
    cin >> A >> B >> C >> D;
    
    ll divA1 = A/C;
    ll divA2 = B/C + ((A % C == 0)?1:0);
    
    ll divB1 = A/D;
    ll divB2 = B/D + ((A % D == 0)?1:0);
    
    ll divC1 = A/(C*D/__gcd(C, D));
    ll divC2 = B/(C*D/__gcd(C, D)) + ((A % (C*D/__gcd(C, D)) == 0)?1:0);
    
    ll sum = ((ll)abs(divA1 - divA2)) + ((ll)abs(divB1 - divB2));
    ll sub = ((ll)abs(divC1 - divC2));
    
    // cout << "DivA " << abs(divA1 - divA2) << endl;
    // cout << "DivB " << abs(divB1 - divB2) << endl;
    // cout << "Sum : " << sum << endl;
    // cout << "Sub : " << sub << endl;
    
    cout << (ll)((B - A + 1) - (sum - sub)) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    solve();
    
    return 0;
}