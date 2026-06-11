#include<bits/stdc++.h>
using namespace std;
long long a[300005],num[300005],m,n=1,sum[300005],ans[300005];
bool check(long long k,long long x){
    long long pos=upper_bound(a+1,a+n,x)-a-1;
    return sum[pos]+(n-pos-1)*x>=k*x;
}
int main(){
    cin>>m;
    for(long long i=1;i<=m;i++){
        long long x;
        cin>>x;
        num[x]++;
    }
    for(long long i=1;i<=300000;i++){
        if(num[i]) a[n++]=num[i];
    }
    sort(a+1,a+n);
    for(long long i=1;i<n;i++){
        sum[i]=sum[i-1]+a[i];
    }
    long long p=0;
    for(long long i=m;i>=1;i--){
        while(p<m&&check(i,p+1)) p++;
        ans[i]=p;
    }
    for(long long i=1;i<=m;i++){
        cout<<ans[i]<<endl;
    }
}