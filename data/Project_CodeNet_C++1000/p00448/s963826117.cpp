#include<iostream>
#include<string>
#include<algorithm>
#include<map>
#include<set>
#include<utility>
#include<vector>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<time.h>
#define loop(i,a,b) for(int i=a;i<b;i++) 
#define rep(i,a) loop(i,0,a)
#define pb push_back
#define mp make_pair
#define all(in) in.begin(),in.end()
const double PI=acos(-1);
const double EPS=1e-10;
const int inf=1e8;
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
int ma,n,m;
vvi out;
vi d;
void func(int a){
	if(a==n){
		vvi	tmp=out;
		rep(i,n)if(d[i])rep(j,m)tmp[i][j]^=1;
		int sum=0;
		rep(i,m){
			int co=0;
			rep(j,n)if(tmp[j][i])co++;
			sum+=max(co,n-co);
		}
		ma=max(ma,sum);
		return;
	}
	d[a]=1;
	func(a+1);
	d[a]=0;
	func(a+1);
}
int main(){
	while(cin>>n>>m,n+m){
		ma=-1;
		d=vector<int>(n);
		vvi in(n,vi(m));
		rep(i,n)rep(j,m)cin>>in[i][j];
		out=in;
		func(0);
		cout<<ma<<endl;
	}
}