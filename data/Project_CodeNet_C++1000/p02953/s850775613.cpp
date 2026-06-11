#include <bits/stdc++.h>
#define io() ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0); srand(time(NULL));
#define check cout<<"?\n";

using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
 
signed main(){
    io();
    int n; cin >> n;
    vector<ll> v, pos;
    v.push_back(0);
    for(int i = 0, x; i < n; ++i){
        cin >> x;
        v.push_back(x);
    }
    v.push_back(0);
    bool ok = 1;
    for(int i = 1; i < n; ++i){
        if(v[i] >= v[i - 1] && v[i] >= v[i + 1]){
            pos.push_back(i);
        }
    }
    for(int i = 0; i < pos.size(); ++i){
        if(v[pos[i]] > v[pos[i] - 1]){
            --v[pos[i]];
        }
    }
    for(int i = 1; i < n; ++i){
        if(v[i] > v[i + 1]){
            ok &= 0;
            break;
        }
    }
    /*
    4 3 3 2 2 Yes
    4 3 3 3 2 Yes
    7 1 2 3 2 2 2 2 Yes
    */
    puts(ok ? "Yes" : "No");
    return 0; 
}