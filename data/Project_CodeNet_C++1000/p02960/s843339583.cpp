#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define int ll
#define rep(i,n) for(int i=0;i<n;i++)
#define all(in) in.begin(), in.end()
#define INF (sizeof(int) == 4 ? (int)1e9:(int)1e18)
#define EPS 0.0000000001
template<class T, class S> void cmin(T &a, const S &b) { if (a > b)a = b; }
template<class T, class S> void cmax(T &a, const S &b) { if (a < b)a = b; }
template<typename Head, typename Value> auto vectors(const Head &head, const Value &v) { return vector<Value>(head, v); }
template<typename Head, typename... Tail> auto vectors(Head x, Tail... tail) { auto inner = vectors(tail...); return vector<decltype(inner)>(x, inner); }
using ld  = long double;
using pii = pair<int,int>;
using piii = pair<int,pii>;
int W,H;
int dx[]={0,0,1,-1}, dy[]={1,-1,0,0};
bool valid(int x,int y){return (0<=x&&x<W)&&(0<=y&&y<H);}
#define MOD 1000000007LL
signed main(){
    string s; cin >> s;
    auto memo = vectors(s.size() + 1, 10,13,-1LL);
    vector<int>base(s.size() + 1,0LL);
    base[s.size()] = 1;
    
    for(int i = (int)s.size() - 1; i >= 0; --i)
        base[i] = (9 * base[i + 1] + base[i + 1]) % 13;
    for(int i = 0; i < 13; ++i)
        for(int j = 0; j < 10; ++j)
            memo[s.size()][j][i] = (i == j ? 1 : 0);
    
    function<int(int,int,int)>solver = [&](int digit,int num,int cmod){
        if( memo[digit][num][cmod] != -1LL) return memo[digit][num][cmod];
        memo[digit][num][cmod] = 0;
        int temp =  ( base[digit] * num ) % 13;
        int nmod =  (cmod - temp <= 0 ? cmod - temp + 13 : cmod - temp) % 13;
        int nidx = digit;
        if(s[nidx] == '?'){
            for(int i = 0; i < 10; ++i){
                memo[digit][num][cmod] += solver(digit + 1, i, nmod);
                memo[digit][num][cmod] %= MOD;
            }
        } else {
            memo[digit][num][cmod] += solver(digit + 1,s[nidx] - '0',nmod);
            memo[digit][num][cmod] %= MOD;
        }
        return memo[digit][num][cmod];
    };
    int ans = 0;
    if(s.front() == '?'){
        for(int i = 0; i < 10; ++i)
            ans += solver(1,i,5), ans %= MOD;
    } else {
        ans += solver(1,s.front() - '0',5);
    }
    cout << (ans % MOD) << endl;
}
