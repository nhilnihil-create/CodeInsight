#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,k;
    cin>>n>>k;
    int a[n];
    int wa=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        wa+=a[i];
    }
    vector<int>x;
    for(int i=1;i*i<=wa;i++){
        if(wa%i==0){
            x.push_back(i);
            x.push_back(wa/i);
        }
    }
    sort(x.begin(),x.end(),greater<int>());
    for(int i=0;i<x.size();i++){
        int l=0,r=0;
        int b[n];
        for(int j=0;j<n;j++)b[j]=a[j]%x[i],r+=x[i]-b[j];
        sort(b,b+n);
        for(int j=0;j<n;j++){
            l+=b[j],r-=x[i]-b[j];
            if(l==r && l<=k){
                cout<<x[i]<<endl;
                return 0;
            }
        }
    }
}