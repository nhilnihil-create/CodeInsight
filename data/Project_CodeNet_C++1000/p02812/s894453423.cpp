#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)

int main() {
    int n;
    cin>>n;
    vector<char> c(n);
    rep(i,n){
        cin>>c[i];
    }
    int ans=0;
    rep(i,n-2){
        if(c[i]=='A' && c[i+1]=='B' && c[i+2]=='C') ans++;
    }
    cout<<ans<<endl;
}