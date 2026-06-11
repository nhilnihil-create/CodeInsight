#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;
using P = pair<int,int>;
using ll = long long; 

int main(){
    ll n,x,jump;
    cin>>n>>x;
    ll sum=0;
    ll ans=1;
    rep(i,n){
        cin>>jump;
        sum+=jump;
        if(sum<=x){
            ans++;
        }else{
            break;
        }
    }
    cout<<ans<<endl;

}
