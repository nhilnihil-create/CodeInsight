// g++ -std=c++11 a.cpp
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<set>
#include<unordered_map>
#include<utility>
#include<cmath>
#include<random>
#include<cstring>
#include<queue>
#include<stack>
#include<bitset>
#include<cstdio>
#include<sstream>
#include<iomanip>
#include<assert.h>
#include<typeinfo>
#define loop(i,a,b) for(long long i=a;i<b;i++)
#define rep(i,a) loop(i,0,a)
#define FOR(i,a) for(auto i:a)
#define pb push_back
#define all(in) in.begin(),in.end()
#define shosu(x) fixed<<setprecision(x)
#define show1d(v) {rep(_,v.size())cout<<" "<<v[_];cout<<endl;}
#define show2d(v) {rep(__,v.size())show1d(v[__]);}
using namespace std;
//kaewasuretyuui
typedef long long ll;
#define int ll
typedef int Def;
typedef pair<Def,Def> pii;
typedef vector<Def> vi;
typedef vector<vi> vvi;
typedef vector<pii> vp;
typedef vector<vp> vvp;
typedef vector<string> vs;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef pair<Def,pii> pip;
typedef vector<pip>vip;
#define mt make_tuple
typedef tuple<int,int,int,int> tp;
typedef vector<tp> vt;
template<typename A,typename B>bool cmin(A &a,const B &b){return a>b?(a=b,true):false;}
template<typename A,typename B>bool cmax(A &a,const B &b){return a<b?(a=b,true):false;}
const double PI=acos(-1);
const double EPS=1e-9;
Def inf = sizeof(Def) == sizeof(long long) ? 2e18 : 1e9+10;
#define yes cout<<"Yes\n"
#define no cout<<"No\n"
 
int dp[10][60][10];
int co[10][60][10];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	rep(i,10)rep(j,60)rep(k,10)dp[i][j][k]=co[i][j][k]=0;
	
	rep(i,10)rep(j,10){
		int a=i+j;
		if(a<10){
			dp[i][0][j]=a;
			co[i][0][j]=1;
		}else{
			dp[i][0][j]=a/10+a%10;
			co[i][0][j]=2;
		}
		if(i==0)co[i][0][j]--;
	}
	rep(j,59)rep(i,10)rep(k,10){
		int a=dp[i][j][k];
		int c=co[i][j][k]+co[a][j][k];
		a=dp[a][j][k];
		dp[i][j+1][k]=a;
		co[i][j+1][k]=c;
	}
	int n;
	cin>>n;
	int out=0,t=0;
	while(n--){
		int a,b;
		cin>>a>>b;
		rep(i,60)if(1ll<<i&b){
			out+=co[t][i][a];
			t=dp[t][i][a];
		}
	}
	cout<<out<<endl;
}










