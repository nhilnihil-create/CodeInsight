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
    int maxN = 1000000;
    int k, x; cin >> k >> x;
    --k;
    int mn = max(x - k, -maxN);
    int mx = min(x + k, maxN);
    for(int i = mn; i <= mx; ++i){
        cout << i << ' ';
    }
    return 0;
}