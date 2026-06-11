#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main()
{
    ll n;
    cin >> n;
    ll h[n];
    rep(i, n) cin >> h[i];
    for (ll i = n - 1; i > 0; i--)
    {
        if (h[i] < h[i - 1])
            h[i - 1]--;
    }
    rep(i,n-1){
        if(h[i]>h[i+1]){
            cout<<"No"<<endl;
            return 0;
        }
    }
    cout<<"Yes"<<endl;
    return 0;
}