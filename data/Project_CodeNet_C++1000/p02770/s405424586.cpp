
#include <bits/stdc++.h>
using namespace std;
long long d[5001];
long long D[5001];
long long a[5001];
long long b[5001];
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    long long k,q;
    cin>>k>>q;
    int i,j;
    for(i=0 ; i<k ; i++)cin>>d[i];
    for(i=0 ; i<q ; i++){
        long long n,x,m;
        b[-1]=0;
        cin>>n>>x>>m;
        for(j=0 ;j<k ; j++){
            a[j]=d[j]%m;
            if(j==0)b[j]=a[j];
            else b[j]=b[j-1]+a[j];
        }

        long long t=x+(n-1)/k*b[k-1]+(k==1 ? 0 :b[(n-1)%k-1]);
        long long cnt=0;
        for(j=0 ; j<k ; j++){
            if(a[j]==0)cnt--;
        }
        cnt*=(n-1)/k;
        if(k!=1)
        for(j=0 ; j<=(n-1)%k-1 ; j++)if(a[j]==0)cnt--;

        cout<<n-1-(t/m-x/m)+cnt<<"\n";
    }
    return 0;
}
