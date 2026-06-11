#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(void){
    int n,m;
    ll k;
    cin >> n >> m >> k;
    vector<ll> a(n),b(m);
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<m;i++) cin >> b[i];

    vector<ll> sa(n+1,0);
    for(int i=0;i<n;i++) sa[i+1] = sa[i]+a[i];
    for(int i=0;i<m-1;i++) b[i+1] += b[i];


    int ans = 0;
    for(int i=0;i<=n;i++){
        ll rest = k-sa[i];
        if(rest<0) break;

        auto itr = lower_bound(b.begin(),b.end(),rest);
        int tmp = i+(int)(itr-b.begin());
        if(itr!=b.end() && *itr==rest) tmp++;
        ans = max(ans,tmp);
    }

    cout << ans << endl;
    return 0;
}