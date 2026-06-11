#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
using namespace std;
using ll=long long;
constexpr ll mod=1000000007;
constexpr int inf=1000000000;
constexpr ll linf=1000000000000000000;

int main(){
    int n;
    cin>>n;
    long double ans=1;
    rep(i,n){
        long double a;
        cin>>a;
        ans*=a;
        if(ans>1e18){
            ans=-1;
        }
        if(ans<0)ans=-1;
    }
    cout<<(ll)ans<<endl;
}
