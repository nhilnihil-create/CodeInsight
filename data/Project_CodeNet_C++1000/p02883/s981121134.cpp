#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const long long INF = 1e15;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    ll n,k;
    cin >> n >> k;
    vector<ll> a(n),f(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> f[i];

    sort(a.begin(),a.end());
    sort(f.rbegin(),f.rend());

    ll left = -1, right = (ll)1e12+1;
    while(right-left > 1){
        ll mid = (right+left)/2;
        ll tk = k;
        //cout << mid << endl;
        for(int i = 0; i < n; i++){
            if(a[i]*f[i] > mid) tk -= a[i]-(mid/f[i]);
        }
        //cout << mid << " " << tk << endl;
        if(tk >= 0) right = mid;
        else left = mid;
    }
    cout << right << endl;
    return 0;
}