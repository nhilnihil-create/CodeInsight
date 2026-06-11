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
    ll n; cin >> n;
    ll cnter[10][10];rep(i, 10)rep(j, 10)cnter[i][j] = 0;//first, last

    rept(i, 1, n+1){
        string s = to_string(i);
        int first = s[0] - '0', last = s.back() - '0';
        cnter[first][last]++;
    }
    ll sum = 0;
    rept(i, 1, n+1){
        string s = to_string(i);
        int first = s[0] - '0', last = s.back() - '0';
        sum += cnter[last][first];        
    }
    cout << sum << ln;
}
