// https://atcoder.jp/contests/sumitrust2019/tasks/sumitb2019_d
#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int,int> P;

#define rep(i,n) for(int i=0;i<(n);++i)
#define repi(i,a,b) for(int i=int(a);i<(b);i++)
#define repr(i,b,a) for(int i=int(b);i>=(a);i--)
#define all(x) x.begin(),x.end()

const ll mod = 1e9+7;
const ll INF = 1e9;

ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
bool valid(int lx,int ux,int ly,int uy,int x,int y){
	return lx<=x&&x<ux&&ly<=y&&y<uy; 
}
ll power(ll x,ll p){
	if(p==0)return 1;
	ll res=power(x*x%mod,p/2);
	if(p%2==1)res=res*x%mod;
	return res;
}

int main()
{
	int n;
	string s;
	cin>>n>>s;
	vector<vector<int>> pos(10,vector<int>());
	rep(i,n) pos[s[i]-'0'].push_back(i);

	int number[1000]={};
	rep(i,10)rep(j,10)rep(k,10){
		auto it=lower_bound(all(pos[i]),0);
		if(it==pos[i].end())continue;
		int pos_i = *it;
		auto it2 = lower_bound(all(pos[j]), pos_i+1);
		if(it2==pos[j].end())continue;
		int pos_j = *it2;
		auto it3 = lower_bound(all(pos[k]), pos_j+1);
		if(it3!=pos[k].end()) number[100*i+10*j+k]++;
		// if(it3!=pos[k].end()) cout<<100*i+10*j+k<<endl;
	}
	int ans=0;
	for(auto x:number)if(x>0)ans++;
	cout<<ans<<endl;
	return 0;
}