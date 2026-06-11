#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll n,ans = 0;
    cin >> n;
    vector<ll> a(n);
    vector<ll> b(n);
    priority_queue<pair<ll,ll>> pq;
    for(int i = 0;i < n;i ++){
        cin >> a[i];
    }
    for(int i = 0;i < n;i ++){
        cin >> b[i];
        pq.push(make_pair(b[i],i));
    }
    while(!pq.empty()){
        ll i = pq.top().second,ln,rn;
        pq.pop();
        ln = (i==0?b[n-1]:b[i-1]);
        rn = (i==n-1?b[0]:b[i+1]);

        if((b[i]-a[i])%(ln+rn)==0){
            ans += (b[i]-a[i])/(ln+rn);
            b[i] = a[i];
        }else if(ln+rn<b[i]){
            ll k = (b[i]%(ln+rn)==0?b[i]/(ln+rn)-1:b[i]/(ln+rn));
            b[i] -= k*(ln+rn);
            ans += k;
            pq.push(make_pair(b[i],i));
        }else{
            cout << -1 << endl;
            return 0;
        }
    }
    cout << ans << endl;
    return 0;
}