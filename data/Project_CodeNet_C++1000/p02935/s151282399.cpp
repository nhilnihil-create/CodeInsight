#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
const int INF = 1001001001;

int main(){
    int n;
    cin >> n;
    vector<double> V(n);
    rep(i,n) cin >> V.at(i);
    sort(V.begin(),V.end());
    double ans = (V.at(0) + V.at(1)) / 2;
    for(int i = 2;i < n;i++) ans = (ans + V.at(i)) / 2;
    cout << ans << endl;
}         