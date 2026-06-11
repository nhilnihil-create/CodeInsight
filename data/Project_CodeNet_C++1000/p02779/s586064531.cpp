#include <bits/stdc++.h>
using ll = long long;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define ALL(x) x.begin(),x.end()
using namespace std;


int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    set<int> s(ALL(a));
    if (a.size() == s.size()) cout << "YES" << endl;
    else cout << "NO" << endl;
    
    return 0;
}