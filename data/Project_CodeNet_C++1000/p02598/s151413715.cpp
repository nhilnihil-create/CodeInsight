#include<bits/stdc++.h>
using namespace std;
int a[200005],n,k;
bool check(int x){
    int now=0;
    for(int i=0;i<n;i++){
        now+=(a[i]-1)/x;
    }
    return now<=k;
}
int main(){
    cin>>n>>k;
    int maxn=0;
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
        if(a[i]>maxn)   maxn=a[i];
    }
    int l=0,r=1e9;
    while(r-l>1){
        int mid=(l+r)>>1;
        if(check(mid))
            r=mid;
        else
            l=mid;
    }
    cout<<r<<endl;
    return 0;
}