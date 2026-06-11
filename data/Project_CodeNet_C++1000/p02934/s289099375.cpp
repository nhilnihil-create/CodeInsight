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
    vector<ld> v(n);
    ld ans = 0;
    for(int i = 0; i < n; ++i){
        cin >> v[i];
        ans += (1/v[i]);
    }
    cout << fixed << setprecision(15);
    return cout << 1/ans << '\n', 0;
}