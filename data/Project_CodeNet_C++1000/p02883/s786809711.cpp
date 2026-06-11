#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;
const ll INF = 1e15;

int main(){
    ll n,k;
    cin >> n >> k;
    vector<int> a(n),f(n);
    priority_queue<pair<int,int>> pq;
    rep(i,n) cin >> a.at(i);
    rep(i,n) cin >> f.at(i);
    sort(a.begin(),a.end());
    sort(f.rbegin(), f.rend());
    ll l=-1,r=INF;
    while(l+1<r) {
        ll x = (l+r)/2;

        ll nk = 0;
        for(ll i=0;i<n;i++){
            nk += max((ll)0, (ll)a.at(i)-x/f.at(i));
        }
        if(nk <= k) r = x;
        else l = x;
    }

    cout << r << endl;

    return 0;
}