/*
h s, d't skp th si tll i's sved
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
string ans="APPROVED";
int n;
cin>>n;
int x;
for(int i=0;i<n;i++)
{
cin>>x;
if(x%2==0 && (x%3!=0 && x%5!=0))
{
ans="DENIED";
}
}
cout<<ans;
}



/*
 * ||||


 */