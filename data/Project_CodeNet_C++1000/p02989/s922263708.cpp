#include <bits/stdc++.h>
using namespace std;
#define arep(i, x, n) for (int i = int(x); i < (int)(n); i++)
#define rep(i, n) for (long long i = 0; i < n; ++i)
#define pi 3.141592653589793
#define eps 0.00000001
#define INF 1e9 + 7
using ll = long long;

int main(){
    ll n;
    cin >> n;

    vector<ll> v(n);
    rep(i, n){
        cin >> v.at(i);
    }

    sort(v.begin(), v.end());

    int itemNum = v[n/2] - v[n/2-1];
    
    cout << itemNum << endl;
}