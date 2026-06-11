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
bool slv(string s)
{
for(int i=0;i<s.length()/2;i++)
{
if(s[i]!=s[s.length()-1-i])
{
return 0;
}
}
return 1;
}
int main()
{
string s;
cin>>s;
int n=s.length();
if(slv(s) && slv(s.substr(0,(n-1)/2)) && slv(s.substr((n+3)/2-1,n)))
{
cout<<"Yes"<<endl;
}
else
{
cout<<"No";
}
}



/*
 * ||||


 */