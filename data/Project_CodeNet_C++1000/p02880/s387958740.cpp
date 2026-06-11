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
    set<int> s;
    for(int i = 1; i <= 9; ++i){
        for(int j = 1; j <= 9; ++j){
            s.insert(i*j);
        }
    }
    cout << (s.count(n) ? "Yes" : "No") << '\n';
    return 0;
}