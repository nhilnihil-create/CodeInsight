#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for(ll i = 0; i < (ll) n; i++)
#define xrep(i,x,n) for(ll i = (ll) x; i < (ll) n; i++)
#define vl vector<long long>
#define vs vector<string>

int main() {
    ll N; cin >> N;

    bool ans = false;
    xrep(i,1,10){
        if(N % i == 0 && N / i <= 9){
            ans = true;
            break;
        }
    }
    if(ans) cout << "Yes" << endl;
    else cout << "No" << endl;
}