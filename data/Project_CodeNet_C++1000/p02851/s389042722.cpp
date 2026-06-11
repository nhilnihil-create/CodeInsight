#include <bits/stdc++.h>
#define rp(i,n) for(int i=0; i<n; i++)
using namespace std;
using ll=long long;
using P=pair<int,int>;
using G=vector<vector<int>>;

int main(){
    ll n,k;
    cin >> n >> k;
    vector<ll> a(n);
    rp(i,n) cin >> a.at(i);
    vector<ll> res(n+1);
    res[0]=0ll;
    rp(i,n){
        res[i+1]=res[i]+(a[i]-1)%k;
        res[i+1]%=k;
    }
    if(n<k){
        ll ctr=1ll;
        ll ans=0ll;
        sort(res.begin(),res.end());
        rp(i,n){
            if(res[i]==res[i+1]) ctr++;
            else{
                ans+=ctr*(ctr-1ll)/2ll;
                ctr=1ll;
            }
        }
        ans+=ctr*(ctr-1ll)/2ll;
        cout << ans << endl;
        return 0;
    }
    vector<ll> num(k,0);
    ll ans=0ll;
    rp(i,min(n+1,k)){
        num.at(res[i])++;
    }
    for(auto i:num) ans+=i*(i-1ll)/2ll;
    for(int i=k; i<=n; i++){
        num.at(res[i-k])--;
        ans += num.at(res[i]);
        num.at(res[i])++;
    }
    cout << ans << endl;
    return 0;
}