#include<iostream>
#include<cstring>
#include<algorithm>
#include<math.h>
using namespace std;
int main()
{
    long long int i,n,j=0,k,t,c,d,b,a[60];
    cin>>n;
    for(i=0;i<n;i++)
{
    cin>>a[i];
    if(a[i]!=i+1)
    j++;
}
if(j==2 ||j==0)
cout<<"YES"<<endl;
else
cout<<"NO"<<endl;
}
