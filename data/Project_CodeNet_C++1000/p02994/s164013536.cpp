#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)

int main() {
    int n, l;
    cin>>n >>l;
    int ans=0;
    if(l>=0){
        for(int i=1;i<n;i++){
            ans=ans+l+i;
        }
    }else if(l>-n){
        rep(i,n){
            if(l+i==0) continue;
            ans=ans+l+i;
        } 
    }else{
        rep(i,n-1){
            ans=ans+l+i;
        }
    }
    cout<<ans<<endl;
}