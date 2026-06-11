#include <bits/stdc++.h>
using namespace std;

#define ALL(v) v.begin(), v.end()
#define V vector
#define P pair
#define ld long double
#define ll long long
#define mod 1000000007
#define IINF INT_MAX
#define INF 1LL << 30


int main() {
    ll n; cin >> n;

    ll sum = 0;
    for(ll i = n - 1; i >= 1; i--){
        sum += i;
    }
    cout << sum << endl;

    return 0;
}
