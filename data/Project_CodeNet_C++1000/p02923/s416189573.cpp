#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)

int main() {
    int n;
    cin>>n;
    vector<long> h(n);
    int ans=0;
    int count=0;
    rep(i,n){
        cin>>h[i];
        if(i>0 && h[i-1]>=h[i]){
            count++;
        }else if(i>0 && h[i-1]<h[i]){
            ans=max(ans,count);
            count=0;
        }
    }
    ans=max(ans,count);
    cout<<ans<<endl;
}