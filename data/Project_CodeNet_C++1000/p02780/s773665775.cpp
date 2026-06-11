#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define F first
#define S second
#define ii pair < int , int >

const int N=500000;
long double a[N];
long double pre[N];
long double c(int n){

long double test=(n+1)*1.0/2*1.0;
return test;

}
int main()
{
    int n,k;
    long double ans=0.0;
    scanf("%d%d",&n,&k);
    long double tmp=0.0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        pre[i]=c(a[i]);
        if(i<k){
            tmp+=pre[i];
        }
    }

    for(int i=k;i<=n;i++){
    tmp+=pre[i];
    tmp-=pre[i-k];
    ans=max(ans,tmp);
    }
    cout<<fixed<<setprecision(8)<<ans;
}
