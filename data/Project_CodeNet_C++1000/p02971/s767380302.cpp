#include <bits/stdc++.h>
#define io() ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0); srand(time(NULL));
 
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

signed main(){
    io();
    int n; cin >> n;
    vector<int> v(n), cpy;
    for(int i = 0; i < n; ++i){
        cin >> v[i];
    }
    cpy = v;
    sort(v.rbegin(), v.rend());
    for(int i = 0; i < n; ++i){
        if(cpy[i] == v[0]){
            cout << v[1] << '\n';
        }else{
            cout << v[0] << '\n';
        }
    }
    return 0; 
}