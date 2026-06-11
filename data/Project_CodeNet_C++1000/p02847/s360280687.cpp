#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define all(x)(x).begin(), (x).end() // 昇順ソート
#define rall(v)(v).rbegin(), (v).rend() // 降順ソート
#define INF 1LL << 60
typedef long long int LL;
typedef long long int ll;
#define pll pair < ll, ll >
#define F first
#define S second
const int MOD = 1000000007;
template < class T > bool chmax(T & a,const T & b) { if (a < b) { a = b; return true; } return false; }
template < class T > bool chmin(T & a,const T & b) { if (a > b) { a = b; return true; } return false; }
// 任意のlogは　対数の底の変換を使う    log(N) / log(任意の底)

int main() {
    string S;cin >> S;
    if(S == "SUN")cout << 7 << endl;
    if(S == "MON")cout << 6 << endl;
    if(S == "TUE")cout << 5 << endl;
    if(S == "WED")cout << 4 << endl;
    if(S == "THU")cout << 3 << endl;
    if(S == "FRI")cout << 2 << endl;
    if(S == "SAT")cout << 1 << endl;

}