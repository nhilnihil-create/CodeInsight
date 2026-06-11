#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define sqr(x) (x)*(x)
using namespace std;

int main(){
#ifdef LOCAL
    freopen("inp.txt", "r", stdin );
    freopen("ans.txt", "w", stdout);
#endif
    ll k, x; cin >> k >> x;
    if(500*k>=x) cout << "Yes\n";
    else cout << "No\n";
}
