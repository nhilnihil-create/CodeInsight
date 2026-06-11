#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)

int main() {
    int n;
    cin>>n;
    vector<int> a(n);
    vector<int> b(n);
    vector<int> c(n-1);
    vector<int> ad(0);
    long ans=0;
    rep(i,n){
        cin>>a[i];
        if(i>0 && a[i-1]+1==a[i]){
            int aa=a[i-1]-1;
            ad.push_back(aa);
        }
    }
    rep(i,n){
        cin>>b[i];
        ans+=b[i];
    }
    rep(i,n-1){
        cin>>c[i];
    }
    rep(i,ad.size()){
        ans+=c[ad[i]];
    }
    cout<<ans<<endl;
}