#include <bits/stdc++.h>
#define int long long
typedef long long ll;
using namespace std;

const ll MAXN = 200000;

ll N, ans=0, tmp=0;

signed main(){
    cin >> N;
    ll p = pow(10, 9);
    ll Q = p-N%p;
    ll P = N/p+1;
    if(Q==p) {
        P = N/p;
        Q = 0;
    }
    cout << 0 << " " << 0 << " " << p << " " << Q << " " << 1 << " " << P;
    return 0;
}