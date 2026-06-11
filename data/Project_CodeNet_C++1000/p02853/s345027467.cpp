#include <bits/stdc++.h>
#define rep(k,i,n) for(long long i=k;i<n;++i)
using namespace std;
typedef long long ll;
int main(void){
    // Your code here!
    ll ans=0;
    int a[2];
    cin>>a[0]>>a[1];
    rep(0,i,2){
        if(a[i]==1){
            ans+=300000;
        }else if(a[i]==2){
            ans+=200000;
        }else if(a[i]==3){
            ans+=100000;
        }
    }
    if(a[0]==1&&a[1]==1){
        ans+=400000;
    }
    cout<<ans<<endl;
    
}
