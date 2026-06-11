#include <bits/stdc++.h>
#define f(i,j,k) for(int i=j;i<k;i++)
using namespace std;
int gcd(long long s,long long t){
    if(s%t==0){
        return t;
    }
    else{
        return gcd(t,s%t);
    }
}
int main(){
    long long a,b,c,d;
    cin>>a>>b>>c>>d;
    long long e=c*d/gcd(d,c);
    long long ac=(a-1)/c,ad=(a-1)/d,ae=(a-1)/e;
    long long bc=b/c,bd=b/d,be=b/e;
    long long ans=(b-a+1)-(bc-ac)-(bd-ad)+(be-ae);
    cout<<ans<<endl;
    return 0;
}