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
int n,x;
cin>>x>>n;
int vl;
set<int> st;
for(int i=0;i<n;i++)
{
cin>>vl;
st.insert(vl);
}
int mx=mod;
int ans=0;
for(int i=0;i<=200;i++)
{
if(st.count(i)==0 && abs(i-x)<mx)
{
mx=abs(i-x);
ans=i;
}
}
cout<<ans;
}
/*
 *||||

 */