#include<bits/stdc++.h>
using namespace std;
typedef long long  ll;

ll m,n;
ll  a[102];

void solve(){
    cin >> n >> m;
    ll s=0;
    for(int i=0;i<n;++i) {
        cin >> a[i];
        s+=a[i];
    }
    s = (s + 4*m - 1)/(4*m);
    ll cnt=0;
    for(int i=0;i<n;++i)
        cnt += (a[i]>=s);
    cout << (cnt >= m  ?  "Yes" : "No") << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1;
    while(t--)
        solve();
    return  0;
}
