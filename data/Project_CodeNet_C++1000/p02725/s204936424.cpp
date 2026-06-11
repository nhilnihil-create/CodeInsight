#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
typedef map<string, int> msi;

int main(){
    int k, n; cin >> k >> n;
    vector<int> v(n);
    rep(i, n) cin >> v.at(i);
    v.push_back(v.at(0)+k);
    int ans = 0;
    rep(i, n) ans = max(ans, v.at(i+1)-v.at(i));
    cout << k - ans << endl;
    return 0;
}
