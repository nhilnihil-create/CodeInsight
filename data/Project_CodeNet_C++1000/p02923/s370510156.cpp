#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using ll=long long;
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> h(n);
    rep(i,n) cin>>h[i];

    int cnt=0;
    int maxv=0;
    rep(i,n-1){
        if(h[i]>=h[i+1]) cnt++;
        else{
            maxv=max(maxv,cnt);
            cnt=0;
        }
        if(i==n-2) maxv=max(maxv,cnt);
    }
    cout<<maxv<<"\n";
    return 0;    
}