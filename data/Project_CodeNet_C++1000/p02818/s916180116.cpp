#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
int main()
{
     long long int a,b,k,m,n;
     cin>>a>>b>>k;
     if (a>=k)
     {
         m=a-k;
         n=b;
         cout<<m<<" "<<n<<endl;
     }
else if(a+b<=k)
     {
         m=0;
         n=0;
         cout<<m<<" "<<n<<endl;
     }

     else if(a<=k && a+b>=k)
      {m=k-a;
     n=b-m;
         m=0;
            cout<<m<<" "<<n<<endl;

     }


     return 0;
}
