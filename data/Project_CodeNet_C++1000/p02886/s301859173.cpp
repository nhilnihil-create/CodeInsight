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
    vector<int> v(n);
    for(auto &x : v) cin >> x;
    int ans = 0;
    for(int i = 0; i < n; ++i){
        for(int j = i + 1; j < n; ++j){
            ans += v[i]*v[j];
        }
    }
    cout << ans << '\n';
    return 0;
}