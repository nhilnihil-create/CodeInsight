#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ios::sync_with_stdio(false);
    cin.tie();
    ll x, y, a, b, c;
    cin>>x>>y>>a>>b>>c;
    vector<ll> p(a), q(b), r(c);
    for(ll i = 0; i < a; i++)
    cin>>p[i];
    for(ll i = 0; i < b; i++)
    cin>>q[i];
    for(ll i = 0; i < c; i++)
    cin>>r[i];
    sort(p.begin(), p.end(), greater<ll>());
    sort(q.begin(), q.end(), greater<ll>());
    sort(r.begin(), r.end(), greater<ll>());
    ll i = x-1;
    ll j = y-1;
    ll k = 0;
    while (1)
    {
        if(i < 0 || j < 0 || k == c)
        break;
        ll n1 = p[i];
        ll n2 = q[j];
        if(r[k] <= min(n1, n2)){
            break;
        }
        if(n1 < n2){
            p[i] = r[k];
            i -= 1;
            k++;
        }else{
            q[j] = r[k];
            k++;
            j -= 1;
        }
        // cout<<n1<<" "<<n2<<" "<<i<<" "<<j<<" "<<k<<" "<<endl;
    }
    if(i==-1){
        while(j >= 0 && k!=c && r[k] > q[j]){
            q[j] = r[k];
            k++;
            j -= 1;
        }
    }
    if(j ==-1){
        while(i >= 0 && k!=c && r[k] > p[i]){
            p[i] = r[k];
            k++;
            i -= 1;
        }
    }
    ll ans = 0;
    for(int i = 0; i < x; i++){
        ans += p[i];
        // cout<<p[i]<<" ";
    }
    // cout<<endl;
    for(int i = 0; i < y; i++){
        ans+=q[i];
        // cout<<q[i]<<" ";
    }
    // cout<<endl;
    cout<<ans;
    return 0;
}