#include<bits/stdc++.h>
using namespace std;
int main()
{

    long long a,b,c,d,e,f,g,h,i,j,k,l,m,n,t,x,y,z;
    cin>>n;
   map<long ,long>mp;
    for(i=1;i<=9;i++)
    {
for(j=1;j<=9;j++)
{


    mp[i*j]++;
}



    }
    if(mp[n]==0)
cout<<"No"<<endl;
else cout<<"Yes"<<endl;






}
