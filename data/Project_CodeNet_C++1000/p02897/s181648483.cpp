#include <bits/stdc++.h>
#define rep(i,n) for (long long i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<ll,ll>;

int main() {
    ll n;
    cin >> n;
    if (n%2==1) printf("%.15f", (double)(n/2+1)/n);
    else printf("%.15f", (double)(n/2)/n);
    return 0;
}
