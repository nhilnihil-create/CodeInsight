#include <bits/stdc++.h>
#define f(i,j,k) for(int i=j;i<k;i++)
#define f2(i,j,k) for(int i=j;i>k;i--)
using namespace std;
int main(){
    long long n;
    cin>>n;
    long double ans=0,x[n],y[n],d;
    d=n;
    f(i,0,n){
        cin>>x[i]>>y[i];
    }
    f(i,0,n-1){
        f(j,i+1,n){
            ans+=2*sqrt(pow(x[i]-x[j],2)+pow(y[i]-y[j],2));
        }
    }
    cout<<fixed<<setprecision(7)<<ans/d<<endl;
    return 0;
}
