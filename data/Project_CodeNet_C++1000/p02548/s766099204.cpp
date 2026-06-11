#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define pii pair<int,int>
#define fi first 
#define se second 
#define all(x) x.begin(),x.end()
#define sz(x) (int)x.size()
#define pb push_back
#define faster ios_base::sync_with_stdio(0);cin.tie(0);
#define mem(a,v) memset(a,v,sizeof(a))
const ll INF=1e18;
const int mod=1e9+7;
const int iinf=1e9+10;
const int xd[4]={1,0,-1,0},yd[4]={0,1,0,-1};
const int mxN=1e2;
bool v[mxN+1]{};
int main()
{
    faster
    int n;
    cin>>n;
    int ans=0;
    for(int i=1;i<=n;i++){
        ans+=n/i;
        if(n%i==0)
            ans--;
    }
    cout<<ans;
}