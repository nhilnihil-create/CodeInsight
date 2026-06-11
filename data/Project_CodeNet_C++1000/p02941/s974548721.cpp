#define HAVE_STRUCT_TIMESPEC
#include<bits/stdc++.h>
using namespace std;
int a[200007],b[2000007];
priority_queue<pair<int,int> >q;
int n;
int mi(int x){
    return x==1?n:x-1;
}
int pl(int x){
    return x==n?1:x+1;
}
int main(){
    cin>>n;
    for(int i=1;i<=n;++i)
        cin>>a[i];
    for(int i=1;i<=n;++i){
        cin>>b[i];
        q.push({b[i],i});
    }
    long long ans=0;
    while(!q.empty()){
        int i=q.top().second;
        q.pop();
        if(b[i]==a[i])
            continue;
        if(a[i]>b[i]-b[mi(i)]-b[pl(i)])
            return puts("-1"),0;
        int tmp=b[mi(i)]+b[pl(i)];
        int tot=b[i]-a[i];
        ans+=tot/tmp;
        tot%=tmp;
        b[i]=a[i]+tot;
        if(a[i]>b[i])
            return puts("-1"),0;
        if(a[i]!=b[i])
            q.push({b[i],i});
    }
    cout<<ans;
    return 0;
}
