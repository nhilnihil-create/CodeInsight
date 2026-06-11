#include <bits/stdc++.h>
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
using ll = long long;
using P = pair<ll, ll>;
const long double PI = acos(-1.0L);
ll GCD(ll a, ll b) { return b?GCD(b, a%b):a; }
ll LCM(ll a, ll b) { return a/GCD(a, b)*b; }

string s;

int main() {
    cin >> s;
    int slen = s.length();
    int now = 0;
    int x = 1;
    vector<int> cnt(2019, 0);
    ll sum = 0;
    reverse(s.begin(), s.end());
    for(int i = 0; i < slen; ++i) {
        int ch = s[i] - '0';
        cnt[now]++;
        now += (ch*x);
        now %= 2019;
        sum += cnt[now];
        x = x*10%2019;
    }
    cout << sum << endl;
}