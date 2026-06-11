#include<bits/stdc++.h>
#define N 400050
#define int long long
#define pb push_back
#define x first
#define y second
#define all(v) v.begin(),v.end()
#define coffee prince
#define sz(a) (int)a.size()
#define ll long long
#define SIZE N
using namespace std;
ll n,ans;
set< ll > pr;
bool che(int x){
  if(x<2||x>n)return 0;
    ll m = n;
    while((m%x)==0){
        m/=x;
    }
    m%=x;
    if(m==1)return 1;
    return 0;
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n;
    ll val= n-1;
    for(ll i=2;i*i<=val;i++){
        if(val%i)continue;
        pr.insert(i);
        pr.insert(val/i);
    }
    pr.insert(n);
    pr.insert(n-1);
    for(ll i=2;i*i<=n;i++){
        if(n%i)continue;
        pr.insert(i);
        ll j = n/i;
        pr.insert(j);
    }
    for(auto ch : pr)
        if(che(ch))ans++;
    cout<<ans;
        return 0;
}
