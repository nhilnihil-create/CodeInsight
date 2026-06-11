#include<bits/stdc++.h>
#define rp(i,n) for(int i=0; i<n; i++)
using namespace std;
using ll=long long;
using P=pair<int,int>;

ll n,k;

vector<ll> a(200005),f(200005);
ll score(ll s){
    ll tarinai=0;
    rp(i,n) tarinai += max(0ll,a.at(i)-s/f.at(i));
    return tarinai;
}
ll BinarySearch(){
    ll l=0; ll r=1e12;
    while(r-l>1){
        if(score((l+r)/2)>k) l=(l+r)/2;
        else r=(l+r)/2;
    }
    if(score(0)<=k) return 0;
    else return r;
}

int main(){
    cin >> n >> k;
    rp(i,n) cin >> a.at(i);
    rp(i,n) cin >> f.at(i);
    auto aite=a.begin();
    auto fite=f.begin();
    sort(aite,aite+n);
    reverse(aite,aite+n);
    sort(fite,fite+n);
    cout << BinarySearch() << endl;
    return 0;
}