#include <bits/stdc++.h>

#define all(a) a.begin(), a.end()
#define allr(a) a.rbegin(), a.rend()
#define rev(v) reverse(v.begin(), v.end());
#define io() ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0); srand(time(NULL));
#define check cout<<"?\n";
 
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

signed main(){
    io();
    int n, k; cin >> n >> k;
    vector<int> v(n);
    int ans = 0;
    for(auto &x : v){
        cin >> x;
        x >= k ? ++ans : ans;
    }
    return cout << ans << '\n', 0;
}