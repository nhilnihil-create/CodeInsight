#include<bits/stdc++.h>
#define ll long long
#define P pair<ll, ll>
using namespace std;

const ll inf = 1e18;

int main(){
    ll n, m, k;
    cin >> n >> m >> k;
    vector<ll>a(n), b(m);
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<m;i++) cin >> b[i];

    for(int i=1;i<n;i++) a[i] += a[i-1];
    for(int i=1;i<m;i++) b[i] += b[i-1];
    a.push_back(inf);
    b.push_back(inf);

    vector<ll>aa(n, 0), bb(m, 0);
    for(int i=0;i<n;i++){
        if(a[i] > k)break;
        aa[i] = (int)(upper_bound(b.begin(), b.end(), k-a[i])-b.begin());
        aa[i] += i + 1;
    }
    for(int i=0;i<m;i++){
        if(b[i] > k)break;
        bb[i] = (int)(upper_bound(a.begin(), a.end(), k-b[i])-a.begin());
        bb[i] += i + 1;
    }

    ll ans = 0;
    for(int i=0;i<n;i++) ans = max(ans, aa[i]);
    for(int i=0;i<m;i++) ans = max(ans, bb[i]);

    cout << ans << endl;
}