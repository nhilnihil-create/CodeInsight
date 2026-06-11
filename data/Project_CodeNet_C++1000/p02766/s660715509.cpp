#include<bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(){
    ll n, k;
    cin>>n>>k;

    ll ans=0;
    ll num=1;
    while(true){
        if(n/num==0) break;
        ans++;
        num*=k;
    }

    cout<<ans<<endl;
    return 0;
}