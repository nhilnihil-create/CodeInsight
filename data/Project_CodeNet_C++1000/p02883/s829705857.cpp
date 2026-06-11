#include <iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll s=-1,g=1000000000000,a,ans,cnt,n,k,L,m;
vector<ll> u,v;
int main(void){
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>a;
        v.push_back(a);
    }
    for(int i=0;i<n;i++){
        cin>>a;
        u.push_back(a);
    }
    sort(v.begin(),v.end());
    sort(u.begin(),u.end());
    reverse(v.begin(),v.end());
    while(g-s>1){
        m=(s+g)/2;
        cnt=0;
        for(int i=0;i<n;i++){
            L=m/u[i];
            cnt+=max(v[i]-L,0LL);
        }
        if(cnt<=k)g=m;
        else s=m;
    }
    cout<<g<<endl;
}
