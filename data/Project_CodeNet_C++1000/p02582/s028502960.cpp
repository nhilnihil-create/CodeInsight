#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fastIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define rep(i, n)  for(ll i = 0; i < (n); ++i)
#define rep1(i,n)  for(ll i = 1;i <= (n); ++i)
#define pb push_back
#define M 1000000007
unordered_map<ll,ll>mp;

int main()
{
    fastIO
    string s;
    cin>>s;
    int res=0;
    int cnt=0;
    for(int i=0;i<3;i++)
    {
    if(s[i]=='R')
    cnt++;
    else
    cnt=0;
    res=max(res,cnt);
    }
    cout<<res;
	return 0;
}
