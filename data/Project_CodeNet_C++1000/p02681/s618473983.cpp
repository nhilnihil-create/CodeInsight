#include<bits/stdc++.h>
using namespace std;
#define oo (long long)1e18
#define ll long long
#define setdp memset(dp,-1,sizeof(dp))
const ll mod = 1e9+7;
void _IOS(){ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);cin.sync_with_stdio(0);}
#define PI 3.14159265359
int sx,sy,tx,ty;
ll a[200003];
ll b[2003];
bool vis[1009][1009];
struct threeElements{
int f,s,t;
};
int main()
{
   // freopen ("jumping.in","r",stdin);
   _IOS();
   string s,t;
   cin>>s>>t;
   if(t.substr(0,s.length())==s)
    cout<<"Yes"<<endl;
   else
    cout<<"No";
}
