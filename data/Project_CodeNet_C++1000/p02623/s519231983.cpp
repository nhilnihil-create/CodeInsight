#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,k;

int main(){
    cin>>n>>m>>k;
    ll a[n+1],b[m+1]; a[0]=0; b[0]=0;
    for(int i=0; i<n; i++){
        cin>>a[i+1];
        a[i+1]+=a[i];
    }
    for(int i=0; i<m; i++){
        cin>>b[i+1];
        b[i+1]+=b[i];
    }
    int mx=0;
    int r=m;
    for(int i=0; i<n+1; i++){
        while(a[i]+b[r]>k){
            r--;
            if(r<0){
                break;
            }
        }
        if(r<0){
            break;
        }
        mx=max(mx,i+r);
    }
    cout << mx << endl;
}
