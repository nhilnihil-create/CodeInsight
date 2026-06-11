#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
int main(){
    ios::sync_with_stdio(false);
    int n,k,c;
    string s;
    cin >> n >> k >> c >> s;
    vector<bool> r(n+1,true);
    rep(i,n) if(s[i] == 'o') r[i] = false;

    vector<int> sum(n+1,-1), rsum(n+1,-1);
    int i = 0;
    int su = 0;
    while(i < n) {
        if(r[i]==false) {
            su++;
            sum[i+1] = su;
            i+=c;
        }
        i++;
    }
    sum[0] = 0;
    rep(i,n+1) if(sum[i] == -1) sum[i] = sum[i-1];
    i=0;su=0;
    reverse(r.begin(), r.end());
    while(i < n) {
        if(r[i]==false) {
            su++;
            rsum[i+1] = su;
            i+=c;
        }
        i++;
    }
    rsum[0] = 0;
    rep(i,n+1) if(rsum[i] == -1) rsum[i] = rsum[i-1];
    reverse(rsum.begin(), rsum.end());
    rep(i,n) {
        if(sum[i] + rsum[i] < k) {
            cout << i+1 << endl;
        }
    }
}