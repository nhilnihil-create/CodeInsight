#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(void){
    ll n, a, b;
    cin >> n >> a >> b;
    if(a == 0) cout << 0 << endl;
    else cout << (n/(a+b))*a + min(a, n - (n/(a+b))*(a+b)) << endl;
    return 0;
}
