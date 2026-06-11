#include <bits/stdc++.h>
#define io() ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0); srand(time(NULL));
 
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

signed main(){
    io();
    int n; cin >> n;
    vector<ll> v(n);
    ll sum = 0, par = 0;
    for(int i = 0; i < n; ++i){
        cin >> v[i];
        sum += v[i];
        i % 2 ? par += (v[i] + v[i]) : i;
    }
    ll first = sum - par;
    cout << first << ' ';
    for(int i = 0; i < n - 1; ++i){
        first = v[i] + v[i] - first;
        cout << first << ' ';
    }
    return 0;
}