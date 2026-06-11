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
    vector<pair<int,int>> v;
    for(int i = 0, x; i < n; ++i){
        cin >> x;
        pair<int,int> p = {x, i + 1};
        v.push_back(p);
    }
    sort(all(v));
    for(auto &x : v) cout << x.second << ' ';
    return  0;
}