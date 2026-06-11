#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using p = pair<int,int>;
using Graph = vector<vector<int>>;
#define rep(i,n) for(int i = 0; i < (int)(n); ++i)

constexpr double PI = acos(-1);

int main() {
    int k,n;
    cin >> k >> n;
    vector<int> v(n,0);
    rep(i,n) cin >> v.at(i);
    v.emplace_back(k+v.at(0));
    int l = 0;
    rep(i,n) {
    	l = max(l,v.at(i+1)-v.at(i));
    }
    cout << k-l << "\n";
    return 0;
}