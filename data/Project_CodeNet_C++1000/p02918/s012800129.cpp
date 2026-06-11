#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,k;cin>>n>>k;
    string ss;cin>>ss;
    int tot=0;
    rep(i,ss.size()-1){
        if(ss[i]==ss[i+1])tot++;
    }
    cout<<min(tot+2*k,n-1)<<'\n';
    return 0;
}
