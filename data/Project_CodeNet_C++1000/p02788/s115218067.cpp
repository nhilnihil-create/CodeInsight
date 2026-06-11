#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,d,a;
    cin>>n>>d>>a;
    d*=2;
    int x[n],h[n];
    vector<pair<int,int>>p(n);
    for(int i=0;i<n;i++){
        cin>>x[i]>>h[i];
        p[i]={x[i],h[i]};
    }
    sort(p.begin(),p.end());
    for(int i=0;i<n;i++){
        x[i]=p[i].first;
        h[i]=p[i].second;
    }
    int dam[n+1]={},wa[n+1]={};
    long long X=0;
    for(int i=0;i<n;i++){
        h[i]=max(h[i]-wa[i],0);
        int att;
        if(h[i]>0)att=(h[i]-1)/a+1;
        else att=0;
        X+=att;
        dam[i]+=att*a;
        if(x[i]+d<x[n-1])dam[upper_bound(x,x+n,x[i]+d)-x]-=att*a;
        if(i)wa[i]=wa[i-1]+dam[i];
        else wa[i]=dam[i];
        wa[i+1]+=dam[i+1]+wa[i];
    }
    cout<<X<<endl;
    return 0;
}
