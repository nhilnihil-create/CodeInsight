#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll s;

int main(){
    cin >> s;
    ll memo=1e9;
    ll y=(s+memo-1)/memo;
    ll x=y*memo-s;
    cout << 0 << ' ' <<  0 << ' ' << memo << ' ' << 1 << ' ' << x << ' ' << y << endl;
    return 0;
}  
