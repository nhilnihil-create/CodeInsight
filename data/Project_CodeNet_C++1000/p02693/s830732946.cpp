/*
*
* author: ian macleod
*
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef vector<long long int> vll;

#define IO                 \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
 
#define f(i,a,b) for(ll i=a;i<b;i++)
#define fo(i,a,b) for(ll i = a; i<=b;i+=1)
#define rf(i,a,b) for(ll i=a;i>=b;i--)

ll power(ll x, ll y) {
    ll res = 1;     // Initialize result
    x = x ;
    if (y==0)return 1;
    if(x==0)return 0;
    while (y > 0) {
        if (y & 1)
            res = (res*x);
        y = y>>1; // y = y/2
        x = (x*x);  // Change x to x^2
    }
    return res;
}


void solve() {
    
    ll k,a,b;
    cin >> k >> a >> b;
    for (ll i = a; i <= b; i++) {
        if (i % k == 0) {
            cout << "OK" << endl;
            return;
        }
    }
    cout << "NG" << '\n';
    return ;
}



int main() {
    solve();
}

