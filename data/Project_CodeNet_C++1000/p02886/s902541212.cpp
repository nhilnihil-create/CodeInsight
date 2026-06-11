#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)

int main() {
    int n;
    cin>>n;
    vector<int> d(n);
    rep(i,n){
        cin>>d[i];
    }
    long ans=0;
    rep(i,n){
        for(int k=i+1;k<n;k++){
            ans=ans+(d[i]*d[k]);
        }
    }
    cout<<ans<<endl;
}