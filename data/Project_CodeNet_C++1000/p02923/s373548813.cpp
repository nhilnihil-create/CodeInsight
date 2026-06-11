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
    int n; cin >> n;
    vector<ll> v(n);
    for(auto &x : v){
        cin >> x;
    }
    int ans = 0, cur = 0;
    for(int i = 0; i < n - 1; ++i){
        if(v[i] >= v[i + 1]){
            ++cur;
        }else{
            cur = 0;
        }
        ans = max(cur, ans);
    }
    return cout << ans << '\n', 0;
}
