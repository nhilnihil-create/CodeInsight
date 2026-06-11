#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)

int main() {
    int n;
    cin>>n;
    vector<int> a(n);
    vector<int> b(n-1);
    long ans=0;
    rep(i,n-1){
        cin>>b[i];
    }
    rep(i,n-1){
        if(i==0){
            a[i]=b[i];
            a[i+1]=b[i];
        }else{
            a[i+1]=b[i];
        }
        if(a[i]>a[i+1] && a[i]>b[i]) a[i]=b[i];
    }
    rep(i,n){
        ans+=a[i];
    }
    cout<<ans<<endl;
}