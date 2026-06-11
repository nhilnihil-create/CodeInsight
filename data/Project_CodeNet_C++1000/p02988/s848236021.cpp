#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;
using P = pair<int,int>;
using ll = long long; 

int main(){
    ll n,tmp;
    cin>>n;
    vector<ll> num;
    rep(i,n){
        cin>>tmp;
        num.push_back(tmp);
    }

    ll ans=0;
    for(int i=1;i<n-1;i++){
        // cout<<num[i-1]<<","<<num[i]<<","<<num[i+1]<<endl;

        if(num[i-1]<num[i] && num[i]<num[i+1]){
            ans++;
        }else if(num[i-1]>num[i] && num[i]>num[i+1]){
            ans++;
        }
    }

    cout<<ans<<endl;

}
