#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
typedef long long ll;
using namespace std;
const  ll INF = 1e9;
const  ll MOD = 1e9 + 7;
#define repi(i,n,init) for(ll i=init;i<(n);i++)

void dump(vector<ll> &a){
    for(ll e : a){
        cout << e << " ";
    }
    cout << endl;
}
int main()
{
    ll n,k;
    cin >> n >> k;
    vector<ll> a(n),f(n);
    repi(i,n,0)cin >> a[i];
    repi(i,n,0)cin >> f[i];
    sort(a.begin(),a.end());
    sort(f.rbegin(),f.rend());
    ll l = -1,r = 1e12;
    while(l + 1 < r){
        ll c = (l + r) / 2;
        ll sum = 0;
        repi(i,n,0)sum += max(0ll, (a[i] - c/f[i]));
        if(sum <= k)r = c;
        else l = c;
    }
    cout << r << endl;
    return 0;
}