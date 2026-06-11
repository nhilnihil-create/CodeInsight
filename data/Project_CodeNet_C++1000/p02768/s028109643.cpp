#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int bigmod(int a,int k,int m)
{
    int ans=1;
    while(k)
    {
        if(k%2) ans=(long long )ans*a%m;
        a=(long long) a*a%m;
        k/=2;
    }
    return ans;
}
int main()
{

    ll n,a,b,i,j=1,k,l=1,m;
    k=1e9+7;
    cin>>n>>a>>b;

    m=bigmod(2,n,k);
    m-=1;
    for(i=0;i<a;i++) {j=j*(n-i)%k;
                    l=l*(i+1)%k;
    }

    l=bigmod(l,k-2,k);
    a=j*l%k;
    j=l=1;
    for(i=0;i<b;i++) {j=j*(n-i)%k;
                    l=l*(i+1)%k;
    }

    l=bigmod(l,k-2,k);
    b=j*l%k;
    m-=a;
    if(m<0) m+=k;
    m-=b;
    if(m<0) m+=k;
    cout<<m<<endl;
    return 0;
}
