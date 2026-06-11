#include<bits/stdc++.h>
using namespace std;
#define int long long int
int m=1000000007 ;
int power(int a,int b)
{ 
 int t=b,p=1,v=a;
    while(t)
    {if((t&1)==1)
     p= (p*v)%m;
        
        v= (v*v)%m;
        t>>=1;
    }
    return p;
}

int32_t main()
{int n,ans;
 cin>>n;
 ans= (power(10,n)+power(8,n))%m;
 ans= (ans- (2*power(9,n))%m +m)%m;
   cout<<ans;
 return 0;
}