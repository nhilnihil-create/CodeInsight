#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<long long, long long>;
constexpr char ln =  '\n';
constexpr long long MOD = 1000000007LL;
constexpr long long INF = 1001001001LL;
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define rept(i, j, n) for(int i=(j); i<(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main(){ 
    string s; cin >> s;
    int n = s.size();
    vector<int> ans(n);
    rep(ri, 2){
        int cnt = 0;
        rep(i, n){
            if(s[i]=='R')cnt++;
            else{
                ans[i] += cnt/2;
                ans[i-1] += (cnt+1)/2;//cntが奇数なら1増える
                cnt = 0;
            }
        }

        reverse(all(ans));
        reverse(all(s));
        rep(i, n){
            if(s[i]=='L')s[i] = 'R';
            else s[i] = 'L';
        }
    }
    rep(i, n)cout << ans[i] << " ";
    cout << ln;
}

