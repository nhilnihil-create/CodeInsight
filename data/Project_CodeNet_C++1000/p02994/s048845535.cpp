#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll=long long;

int main(){
    int n,l;
    cin>>n>>l;
    int ans=0,mn=1e9,x;
    rep(i,n){
        ans+=l+i;
        if(mn>abs(l+i)){
            mn=abs(l+i);
            x=l+i;
        }
    }
    cout<<ans-x<<endl;
}