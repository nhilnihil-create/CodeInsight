#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

int main()
{
    int n;
    ll k;
    cin >> n >> k;
    ll a[503];
    ll s = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        s += a[i];
    }
    vector<ll> v;
    for(ll i = 1; i * i <= s; i++){
        if(s % i == 0){
            v.push_back(i);
            if(i * i != s) v.push_back(s / i);
        }
    }
    sort(v.begin(), v.end(), greater<ll>());
    for(ll d : v){
        ll t = 0;
        ll b[503];
        for(int i = 0; i < n; i++){
            b[i] = a[i] % d;
            t += b[i];
        }
        sort(b, b + n, greater<ll>());
        ll r = 0;
        for(int i = 0; i < n; i++){
            if(t == r) break;
            t -= b[i];
            r += d - b[i];
        }
        if(t <= k){
            cout << d << endl;
            return 0;
        }
    }
}
