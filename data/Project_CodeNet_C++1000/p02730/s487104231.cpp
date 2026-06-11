#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<long long, long long>;
constexpr char ln =  '\n';
constexpr long long MOD = 1000000007LL;
constexpr long long INF = 1001001001LL;
constexpr long long LINF = 1001001001001001001;
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define rept(i, j, n) for(int i=(j); i<(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main(){
    string s; cin >> s;
    int n = s.size();
    string a = s.substr(0, (n-1)/2);
    string b = s.substr((n+3)/2-1);
    string ar = a, br = b, sr = s;
    reverse(all(ar)), reverse(all(br)), reverse(all(sr));
    if(s==sr && a==ar && b==br)cout << "Yes" << ln;
    else cout << "No" << ln;
}