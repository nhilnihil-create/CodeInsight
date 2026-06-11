#include <bits/stdc++.h>
#define rep(i, n)	for(int i=0;i<(int)(n);i++)
using namespace std;
using ll=long long;

int main(){
    int n,k;
    cin>>n>>k;
    vector<int> hp(n);
    rep(i, n) cin>>hp[i];
    sort(hp.begin(),hp.end());
    ll ans=0;
    if(n>=k){
        rep(i,n-k){
            ans+=hp[i];
        }
    }
    cout<<ans<<endl;
}