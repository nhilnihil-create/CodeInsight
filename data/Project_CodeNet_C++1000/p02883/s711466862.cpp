#include<bits/stdc++.h>
using namespace std;

int main(){
    long long n,k;cin>>n>>k;
    vector<long long>a(n),f(n),c(n);
    vector<pair<long long,long long>>b(n);
    for(int i=0;i<n;++i){
        cin>>a[i];
    }
    for(int i=0;i<n;++i){
        cin>>f[i];
    }
    sort(a.begin(),a.end());
    sort(f.begin(),f.end());
    reverse(f.begin(),f.end());
    for(int i=0;i<n;++i){
        b[i].first=a[i]*f[i];
        b[i].second=f[i];
    }
    sort(b.begin(),b.end());
    for(int i=0;i<n;++i)c[i]=b[i].first;
    long long r=b[n-1].first,l=0;
    while(r-l>1){
        long long m=(r+l)/2,cnt=0;
        int h=upper_bound(c.begin(),c.end(),m)-c.begin();
        for(int i=h;i<n;++i){
            if(b[i].first-m>0){cnt+=(b[i].first-m)/b[i].second;
            if((b[i].first-m)%b[i].second>0)cnt++;}
        }
        if(cnt>k)l=m;
        else{
            r=m;
        }
    }
    long long ans=r;
    long long m=(r+l)/2,cnt=0;
    int h=upper_bound(c.begin(),c.end(),l)-c.begin();
    for(int i=h;i<n;++i){
        if(b[i].first-m>0){cnt+=(b[i].first-m)/b[i].second;
        if((b[i].first-m)%b[i].second>0)cnt++;}
    }
    if(cnt<=k)ans=l;
    cout<<ans<<endl;
}