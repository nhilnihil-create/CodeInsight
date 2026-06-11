#include <bits/stdc++.h>
#define For(i, a, b) for(int (i)=(int)(a); (i)<(int)(b); ++(i))
#define rFor(i, a, b) for(int (i)=(int)(a)-1; (i)>=(int)(b); --(i))
#define rep(i, n) For((i), 0, (n))
#define rrep(i, n) rFor((i), (n), 0)
#define fi first
#define se second
using namespace std;
typedef long long lint;
typedef unsigned long long ulint;
typedef pair<int, int> pii;
template<class T> bool chmax(T &a, const T &b){if(a<b){a=b; return true;} return false;}
template<class T> bool chmin(T &a, const T &b){if(a>b){a=b; return true;} return false;}
template<class T> T div_floor(T a, T b){
    if(b < 0) a *= -1, b *= -1;
    return a>=0 ? a/b : (a+1)/b-1;
}
template<class T> T div_ceil(T a, T b){
    if(b < 0) a *= -1, b *= -1;
    return a>0 ? (a-1)/b+1 : a/b;
}

constexpr lint mod = 1e9+7;
constexpr lint INF = mod * mod;
constexpr int MAX = 1000010;

vector<int> fact;

void setfact(int n){
    fact.resize(n+1);
    for(int t=2; t<=n; t*=2){
        for(int i=t; i<=n; i+=t) ++fact[i];
    }
    partial_sum(fact.begin(), fact.end(), fact.begin());
}

int getC(int n, int r){
    return r == 0 || fact[n] <= fact[r] + fact[n-r];
}

int main(){
    int n; string s;
    cin >> n >> s;
    setfact(n);
    bool flag = false;
    for(auto &a: s){
        --a;
        if(a == '1') flag = true;
    }
    if(flag){
        int b = 0;
        rep(i, n)if(s[i] == '1') b ^= getC(n-1, i);
        printf("%d\n", b);
    }
    else{
        int b = 0;
        rep(i, n)if(s[i] == '2') b ^= getC(n-1, i);
        printf("%d\n", b*2);
    }
}