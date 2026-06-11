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
int n;
cin>>n;
int mx=0;
map<string,int> mp;
string s[n];
for(int i=0;i<n;i++)
{
cin>>s[i];
mp[s[i]]++;
mx=max(mx,mp[s[i]]);
}
vector<string> ans;
for(int i=0;i<n;i++)
{
if(mp[s[i]]==mx)
{
ans.push_back(s[i]);
mp[s[i]]=0;
}
}
sort(ans.begin(),ans.end());
for(int i=0;i<ans.size();i++)
{
cout<<ans[i]<<endl;
}
}



/*
 * ||||


 */