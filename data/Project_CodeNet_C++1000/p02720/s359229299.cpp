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


void lunlun(ll num, vector<ll>& res){
    if(num > 3234566667) return;
    res.push_back(num);
    ll last = num % 10;
    if(last!=0) lunlun(num*10 + last-1, res);
    lunlun(num * 10 + last, res);
    if(last!=9) lunlun(num*10+last+1, res);
}

int main(){
    int k; cin >> k;
    vector<ll> res;
    rept(i, 1, 10){
        lunlun(i, res);
    }
    sort(all(res));
    cout << res[k-1] << ln;
}