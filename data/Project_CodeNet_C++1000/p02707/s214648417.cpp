#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(){
    int n;
    cin >> n;
    vector<int> a(n+1);
    vector<int> ans(n+1);
    for(int i = 2; i <= n; ++i){
        cin >> a[i];
        ++ans[a[i]];
    }
    for(int i = 1; i <= n; ++i) cout << ans[i] << endl;
    return 0;
}