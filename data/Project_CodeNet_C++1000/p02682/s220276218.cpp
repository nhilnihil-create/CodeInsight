#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
using namespace std;
using ll=long long;
constexpr ll mod=1000000007;
constexpr int inf=1000000000;
constexpr ll linf=1000000000000000000;

int main(){
    int a,b,c,k;
    cin>>a>>b>>c>>k;
    int ans=0;
    if(a>=k)ans=k;
    else{
        ans=a;
        k-=a+b;
        if(k>0)ans-=k;
    }
    cout<<ans<<endl;
}
