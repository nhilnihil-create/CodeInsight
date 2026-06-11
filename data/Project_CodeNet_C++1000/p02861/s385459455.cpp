// https://atcoder.jp/contests/abc145/tasks/abc145_c
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

double dist(P p1, P p2){
	return sqrt(pow(p1.first-p2.first,2) + pow(p1.second-p2.second,2));
}

int main()
{
	int n;
	cin>>n;
	vector<P> p(n);
	rep(i,n)cin>>p[i].first>>p[i].second;

	vector<int> town(n);
	iota(all(town),0);
	int cnt=0;
	double sum=0;
	do{
		rep(i,n-1){
			sum+=dist(p[town[i]],p[town[i+1]]);
		}
		cnt++;
	}while(next_permutation(all(town)));

	cout<<setprecision(15)<<sum/cnt<<endl;
	return 0;
}