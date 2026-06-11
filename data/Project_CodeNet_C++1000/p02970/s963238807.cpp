#include <bits/stdc++.h>
#define io() ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0); srand(time(NULL));
 
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

signed main(){
    io();
    ll n, d; cin >> n >> d;
    d += d;
    ++d;
    if(n % d == 0){
        cout << n/d << '\n';
    }else{
        cout << n/d  + 1 << '\n';
    }
    return 0;
}