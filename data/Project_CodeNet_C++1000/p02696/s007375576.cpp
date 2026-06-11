#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i< (n); i++)
using namespace std;
using ll = long long;
typedef pair<int,int> P;

ll A,B,N; 

ll floor(ll xx) {
    ll a = A*xx/B;
    ll bb = xx/B;
    ll b = A*bb;
    return a - b;
}

int main(void) {
    cin >> A >> B >> N;
    ll ans;
    if(N<B) {
        ll x = N;
        ans = floor(x);
    }
    else {
        ll x = B-1;
        ans = floor(x);
    }
    cout << ans << endl;
    return 0;
}