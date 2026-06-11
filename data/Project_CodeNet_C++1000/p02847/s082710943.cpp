/*
17/10/2017
*/
#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
int main()
{
string s[7]={"SUN", "MON", "TUE", "WED","THU", "FRI","SAT"};
string t;
cin>>t;
int ps=0;
for(int i=0;i<7;i++)
{
if(s[i]==t)
{
ps=i;
break;
}
}
cout<<7-ps<<endl;
}