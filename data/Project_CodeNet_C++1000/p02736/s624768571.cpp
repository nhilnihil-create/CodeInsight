///In the name of GOD
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MXN = 1e6 + 10;
const ll LOG = 22;
ll n, sum, xr;
ll A[MXN], B[MXN];
string s;
bool C(ll n, ll r){
    return (n || !r);
}
bool shd(ll n, ll r){
    for(int i = 0; i < LOG; i ++){
        if(!C((n >> i) & 1LL, (r >> i) & 1LL)) return 0;
    }
    return 1;
}
bool C_parity(ll n, ll r){
    return n == (r | (n - r));
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
    cin >> n >> s;
    for(int i = 0; i < n; i ++) A[i] = s[i] - '0' - 1, B[i] = A[i] / 2;
    for(int i = 0; i < n; i ++){
        if(shd(n - 1, i) && A[i] % 2) xr = xr ^ 1;
    }
    if(xr) return cout << 1, 0;
    for(int i = 0; i < n; i ++) if(A[i] == 1) return cout << 0, 0;
    for(int i = 0; i < n; i ++){
        if(C_parity(n - 1, i)) xr = xr ^ (B[i]);
    }
    cout << (xr ? 2 : 0);
    return 0;
}
/*!
    Be careful who you share your weaknesses with.
    Some people can't wait for the opportunity to use them against you!!
*/
//! N.N
