#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int INF = (1<<30) - 1;
const ll LINF = (1LL<<60) - 1;

int main(){
    string s;
    cin >> s;
    if (s == "SUN") cout << 7 << endl;
    if (s == "MON") cout << 6 << endl;
    if (s == "TUE") cout << 5 << endl;
    if (s == "WED") cout << 4 << endl;
    if (s == "THU") cout << 3 << endl;
    if (s == "FRI") cout << 2 << endl;
    if (s == "SAT") cout << 1 << endl;
}