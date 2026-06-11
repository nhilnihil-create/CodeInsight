#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
const int INF = 1001001001;

int main(){
    int n;
    cin >> n;
    vector<int> b(n-1);
    rep(i,n-1) cin >> b.at(i);
    vector<int> a(n,0);
    a.at(0) = b.at(0);
    a.at(n-1) = b.at(n-2);
    for(int i = 0; i < n - 2;i++){
        int t = 0;
        if(b.at(i) <= b.at(i+1)) t = b.at(i);
        else t = b.at(i+1);
        a.at(i+1) = t;
    }
    int ans = 0;
    rep(i,n) ans += a.at(i);
    cout << ans << endl;
}