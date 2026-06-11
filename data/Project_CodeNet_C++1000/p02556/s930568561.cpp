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
int main()
{
	faster
	int n;
	cin>>n;
	int mm1=-mod,mm3=mod,mm2=mod,mm4=-mod;
	for(int i=0,a,b;i<n;i++){
		cin>>a>>b;
		mm1=max(mm1,a+b);
		mm2=min(mm2,a-b);
		mm3=min(mm3,a+b);
		mm4=max(mm4,a-b);
		//cout<<mm1<<" "<<mm2<<" "<<mm3<<" "<<mm4<<"\n";
	}
	cout<<max(mm4-mm2,mm1-mm3);
}