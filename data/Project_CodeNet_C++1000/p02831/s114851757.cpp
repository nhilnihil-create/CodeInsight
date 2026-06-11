#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for(ll i = 0; i < (ll) n; i++)
#define xrep(i,x,n) for(ll i = (ll) x; i < (ll) n; i++)
#define vl vector<long long>
#define vs vector<string>
#define SORT(A) sort(A.begin(), A.end())

int main() {
    ll a,b;
    cin >> a >> b;

    ll g = 1;
    for(ll i = min(a,b); i > 0; i--){
        if(a % i == 0 && b % i == 0){
            a /= i;
            b /= i;
            g = i;
            break;
        }
    }

    cout << a * b * g << endl;
}