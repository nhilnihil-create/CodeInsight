#include <bits/stdc++.h>
#define repp(i,l,r)for(long long i=(l);i<(r);i++)
#define rep(i,n) for (long long i = 0; i < (n); ++i)
#define per(i,n) for (long long i = (n); i >= 0; --i)
const int INF = 2147483647;//int max
const long long int MOD = 1000000007;
using namespace std;
using ll = long long;
using P = pair<int,int>;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

void dfs(int n, char mx, string S){
    if(n == S.length()){
        cout << S << "\n";
        return;
    }
    for(char c = 'a'; c <= mx + 1;c++) dfs(n,max(mx,c),S + c);
}

//ミョ(-ω- ?)
int main() {
    int n;
    cin >> n;
    dfs(n,'a'-1,"");
    return 0;
}