#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
const int INF = 1001001001;
const int mod = 1000000007;

int main(){
    int n,x;
    cin >> n >> x;
    vector<int> l(n);
    rep(i,n) cin >> l.at(i);
    int d = 0;
    int ans = 1;
    rep(i,n){
        d += l.at(i);
        if(d > x)break;
        ans++;
    }
    cout << ans << endl;
}