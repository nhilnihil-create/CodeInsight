#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define int long long

  
int32_t main()
{


	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int n;
    cin>>n;
 map<string ,int> mp;

for(int  i=0;i<n;i++)
{
    string s;
    cin>>s;
   sort(s.begin(),s.end());
mp[s]++;

}
int count=0;
for(auto it=mp.begin();it!=mp.end();it++)
{
    int x=it->second;
    if(x>1)
    count+=(x*(x-1))/2;
}
cout<<count;
}
