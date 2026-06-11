#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
const int INF = 1001001001;

int main(){
    int n;
    cin >> n;
    vector<int> d(n);
    rep(i,n) cin >> d.at(i);
    sort(d.begin(),d.end());
    int ne = n/2;
    int ns = n/2 - 1;
    int ans = d.at(ne) - d.at(ns);
    cout << ans << endl;
}