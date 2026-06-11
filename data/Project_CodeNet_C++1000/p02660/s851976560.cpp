#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
using namespace std;
using ll=long long;
constexpr ll mod=1000000007;
constexpr int inf=1000000000;
constexpr ll linf=1000000000000000000;

int main(){
    ll n;
    cin>>n;
    int ans=0;
    for(ll i=2;i*i<=n;++i){
        if(n%i!=0)continue;
        int cnt=0;
        while(n%i==0){
            n/=i;
            ++cnt;
        }
        for(int j=2;;++j){
            if(j*(j+1)/2>cnt){
                ans+=j-1;
                break;
            }
        }
    }
    if(n!=1)++ans;
    cout<<ans<<endl;
}
