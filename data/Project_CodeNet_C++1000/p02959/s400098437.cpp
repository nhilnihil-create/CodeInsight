#include <bits/stdc++.h>
#define io() ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0); srand(time(NULL));
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
 
signed main(){
    io();
    int n; cin >> n;
    vector<ll> a(n + 1), b(n);
    for(int i = 0; i <= n; ++i){
        cin >> a[i];
    }
    for(int i = 0; i < n; ++i){
        cin >> b[i];
    }
    ll tot = 0;
    for(int i = 0; i < n; ++i){
        if(b[i] >= a[i]){
            tot += a[i];
            b[i] -= a[i];
        }else{
            tot += b[i];
            b[i] = 0;
        }
        if(b[i] >= a[i + 1]){
            tot += a[i + 1];
            a[i + 1] = 0;
        }else{
            tot += b[i];
            a[i + 1] -= b[i];
        }
    }
    cout << tot << '\n';
    return 0; 
}