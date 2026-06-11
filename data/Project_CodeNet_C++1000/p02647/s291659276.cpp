#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
int main(){
    ios::sync_with_stdio(false);
    int n,k;
    cin >> n >> k;
    vector<int> a(n);
    rep(i,n) {
        cin >> a[i];
    }
    rep(i,k) {
        bool end_flag = true;
        vector<int> s(n,0); //a[i] = s[0] + s[1] + ... + s[i]
        rep(i,n) {
            s[max(0,i-a[i])]++;
            if(i+a[i]+1 < n) s[i+a[i]+1]--;
        }
        a[0] = s[0];
        rep(i,n-1) {
            a[i+1] = a[i] + s[i+1];
        }
        rep(i,n) if(a[i] != n) end_flag = false;
        if(end_flag) break;
    }
    rep(i,n) {
        cout << a[i] << endl;
    }
}
