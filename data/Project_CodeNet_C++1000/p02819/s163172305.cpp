/*
h s, d't skp th si tll i's sved
 * ABC141 E
 * ABC145 D
 * ABC147 F
*/
#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
bool is_pri(int n)
{
for(int i=3;i<=sqrt(n);i+=2)
{
if(n%i==0)
{
return 0;
}
}
return 1;
}
int main()
{
int n;
cin>>n;
if(n==2)
{
cout<<n;
}
else
{
if(n%2==0)
{
n++;
}
while(!is_pri(n))
{
n+=2;
}
cout<<n<<endl;
}
}