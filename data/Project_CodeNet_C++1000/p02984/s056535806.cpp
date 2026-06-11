#include "bits/stdc++.h"
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll =long long;
using P =pair<int,int>;

int main(){
    int n;
    ll s=0;
    cin >> n;
    vector <ll> a(n);

    rep(i,n){
        cin >> a[i];
        s+=a[i]*pow(-1,i);
    }

    vector <ll> ans(n);
    rep(i,n){
        ans[i]=s;
        s=2*a[i]-s;
    }

    rep(i,n){
        cout << ans[i] << endl;
    }
    

    return 0;
}