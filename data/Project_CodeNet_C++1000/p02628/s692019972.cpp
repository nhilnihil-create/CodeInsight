//arif//c++//vjudge
#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include<vector>
using namespace std;
int main()

{
int t,e,f,a,b,z,c,i,d;

cin>>t>>e;
int s[t];
int sum=0;
for( i=0;i<t;i++)
{
cin>>s[i];

}

for( i=0;i<e;i++)
{
sort(s,s+t);
sum=sum+s[i];

}

cout<<sum<<endl;
}

    