#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

/*
long long hspow(long long x, long long n){
    if(n == 0) return 1;
    if(n % 2 == 0) return hspow(x * x, n / 2);
    else return x * hspow(x, n - 1);
}
*/
/*
ll hspow(ll a, ll n){
    ll x = 1;
    while(n > 0){
        if(n & 1){
            x = x * a;
        }
        a = a * a;
        n >>=1;
    }
    return x;
}
*/
ll func(ll H){
    if(H == 1) return 1;
    else return 2 * func(H/2) + 1;
}

void solve(long long H){
    cout << func(H) << endl;
    return;
}

int main(){
    long long H;
    scanf("%lld",&H);
    solve(H);
    return 0;
}
