#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define inf 1001001001001001001
#define mod 1000000007
#define mod2 998244353
#define pi acos(-1)
#define all(v) v.begin(),v.end()
int main(){
    int N;cin>>N;
    vector<int>d(N);
    ll ans=0;
    rep(i,N){
        cin>>d.at(i);
    }
    for(int i=0;i<N-1;i++){
        for(int j=i+1;j<N;j++){
            ans+=d.at(i)*d.at(j);
        }
    }
    cout<<ans<<endl;

}