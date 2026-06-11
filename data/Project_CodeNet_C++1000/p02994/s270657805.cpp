#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
const int INF = 1001001001;
const int mod = 1000000007;

int main(){
    int n,l;
    cin >> n >> l;
    vector<int> v(n);
    int total = 0;
    rep(i,n) {
        v.at(i) = i + l;
        total += v.at(i);
    }
    int d = INF;
    rep(i,n) d = min(d,abs(v.at(i)));
    int ans = total >= 0 ? total - d : total + d;
    cout << ans << endl; 
}