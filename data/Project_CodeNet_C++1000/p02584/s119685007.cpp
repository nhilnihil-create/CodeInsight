#include <bits/stdc++.h>
using namespace std;
int main()
{
 long long i,j,k,a,b,c=0,n,x,y,d;
 cin>>x>>k>>d;
 x=abs(x);
 y=x/d;
 if(y>=k) cout<<x-(k*d)<<endl;
 else
 {
   k=k-y;
   if(k%2==0) cout<<x-(y*d)<<endl;
   else cout<<abs(x-(y+1)*d)<<endl;
 }
return 0;
}
