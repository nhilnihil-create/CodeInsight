#include <bits/stdc++.h>
#define f(i,j,k) for(int i=j;i<k;i++)
#define f2(i,j,k) for(int i=j;i>k;i--)
using namespace std;
int main(){
    long long n,sum=0;
    cin>>n;
    long long a[n],b[n];
    f(i,0,n){
        cin>>a[i];
        sum+=a[i];
    }
    long long ans=sum,sum2=0;
    f(i,0,n){
        sum2+=a[i];
        ans=min(ans,abs(2*sum2-sum));
    }
    cout<<ans<<endl;
    return 0;
}
