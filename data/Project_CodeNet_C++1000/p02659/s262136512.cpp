#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;

#define rep(i,n) for (int i = 0; i < (n); ++i)


void solve(long double A, long double B){
    ll b = B*100 + 0.5;
    ll ans = A * b;
    ans /= 100;
    cout << ans << endl;
}

int main(){
    long long A;
    scanf("%lld",&A);
    long double B;
    scanf("%Lf",&B);
    solve(A, B);
    return 0;
}
