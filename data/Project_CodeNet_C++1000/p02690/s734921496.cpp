#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i< (n); i++)
using namespace std;
using ll = long long;
typedef pair<int,int> P;

int main(void) {
    ll x; cin >> x;
    ll y;
    for(int a=-120; a<=120; a++) {
        for(int b=-120; b<=120; b++) {
            ll ans = pow(a,5) - pow(b,5);
            if(x == ans) {
                cout << a << " " << b << endl;
                return 0;
            }
        }
    }
}