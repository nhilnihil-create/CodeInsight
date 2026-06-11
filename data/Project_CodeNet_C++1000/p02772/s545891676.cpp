#include<bits/stdc++.h>
using namespace std;
using ll = long long ;
int main()
{
   int n;
   cin>>n;
   int f=1;
   for(int i=0;i<n;i++)
   {
       int x;
       cin>>x;
       if(x%2==0&&(x%3==0||x%5==0))continue;
       else if(x%2==0)f=0;
   }
   if(f)cout<<"APPROVED"<<endl;
   else cout<<"DENIED"<<endl;
}
