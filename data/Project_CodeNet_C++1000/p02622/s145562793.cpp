#include "bits/stdc++.h"
using namespace std;
using ll = long long;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REP(n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)

int main() {
    int num,a, b, c, d;
    a = b = c = d = 0;
    string s,t;
    cin >> s>> t;
    num = s.length();

    REP(num) {
        if (s[i] != t[i]) {
            s[i] = t[i];
            a++;
        }
    }

    cout << a << endl;
}
 