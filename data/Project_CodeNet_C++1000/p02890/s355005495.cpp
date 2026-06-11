#include<bits/stdc++.h>
using namespace std;
#define next Next
#define last Last
#define int long long
const int N=1e6+5;
int n,a[N],sum[N];
/*char buf[1<<21],*p1=buf,*p2=buf;
inline int gc(){return p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++;}*/
#define gc getchar
inline int read()
{
	int ret=0,f=0;char c=gc();
	while(!isdigit(c)){if(c=='-')f=1;c=gc();}
	while(isdigit(c)){ret=ret*10+c-48;c=gc();}
	if(f)return -ret;return ret;
}
signed main()
{
    n=read();
    for(int i=1;i<=n;i++)a[read()]++;
    sort(a+1,a+n+1);
//    cout<<a[1]<<" "<<a[2]<<" "<<a[3]<<endl;
    for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
    for(int i=1;i<=n;i++)
    {
        int l=0,r=n/i;
        while(l<r)
        {
            int mid=(l+r+1)/2;
            if(mid>a[n])
            {
                if(i*mid<=sum[n])l=mid;
                else r=mid-1;
            }
            else{
                int x=lower_bound(a+1,a+n+1,mid)-a;
                x--;
                if(mid*(i-(n-x))<=sum[x])l=mid;
                else r=mid-1;
            }
        }
        printf("%lld\n",l);
    }
}