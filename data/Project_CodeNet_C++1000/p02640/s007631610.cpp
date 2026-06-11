/*
h s, d't skp th si tll i's svedclTabCtrl
 * ABC141 E
 * ABC145 D
 * ABC147 F
 * ABC174 F
*/
#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
int main()
{
int x,y;
cin>>x>>y;
if(y%2==0)
{
int h=y/2;
int k=y/4;
if(y%4!=0)
{
k++;
}
if(x>=k && x<=h)
{
cout<<"Yes"<<endl;
}
else
{
cout<<"No"<<endl;
}
}
else
{
cout<<"No"<<endl;
}
}
/*
 *||||

 */