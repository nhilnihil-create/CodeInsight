#include <bits/stdc++.h>
#define f(i,j,k) for(int i=j;i<k;i++)
#define f2(i,j,k) for(int i=j;i>k;i--)
using namespace std;
int main(){
    long long n,k;
    cin>>n>>k;
    long long a[n];
    long double b[n-k+1];
    b[0]=0;
    f(i,0,k){
        cin>>a[i];
        b[0]+=a[i];
    }
    f(i,k,n){
        cin>>a[i];
        b[i-k+1]=b[i-k]-a[i-k]+a[i];
    }
    sort(b,b+n-k+1);
    cout<<fixed<<setprecision(9)<<(b[n-k]+k)/2<<endl;
    return 0;
}
