#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)

int main() {
    int n, x;
    cin>>n >>x;
    vector<int> l(n);
    int ans=1;
    int d=0;
    rep(i,n){
        cin>>l[i];
        d+=l[i];
        if(d<=x) ans++;
    }
    cout<<ans<<endl;
}