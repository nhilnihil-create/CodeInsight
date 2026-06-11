#include <bits/stdc++.h>
#define rep(i, n)	for(int i=0;i<(int)(n);i++)
using namespace std;
using ll=long long;

int main(){
    int n,k;
    cin>>n>>k;
    int h[n];
    int ans=0;
    rep(i, n){
        cin>>h[i];
        if(h[i]>=k) ans++;
    }
    cout<<ans<<endl;
    
}