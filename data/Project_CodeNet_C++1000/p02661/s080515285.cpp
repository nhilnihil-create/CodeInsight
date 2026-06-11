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
    int a[n],b[n];
    rep(i,n){
        cin>>a[i]>>b[i];
    }
    sort(a,a+n);
    sort(b,b+n);
    int ans;
    if(n%2==1){
        ans=b[n/2]-a[n/2]+1;
    }
    else{
        ans=b[n/2]+b[n/2-1]-a[n/2]-a[n/2-1]+1;
    }
    cout<<ans<<endl;
}
