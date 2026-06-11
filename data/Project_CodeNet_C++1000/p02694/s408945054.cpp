#include <bits/stdc++.h>

using namespace std;

int main()
{
   long long int x;
   cin>>x;
   long long int n=100;
   long long int cnt=0;
   for(int i=1;i<=1e8;i++)
   {

       n=n+(n/100);
       if(n>=x){cout<<i<<endl; break;}
   }

    return 0;
}
