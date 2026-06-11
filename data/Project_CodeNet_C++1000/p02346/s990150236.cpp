#include<iostream>
#include<vector>
#include<string>
#include<algorithm>	
#include<map>
#include<set>
#include<utility>
#include<cmath>
#include<cstring>
#include<queue>
#include<stack>
#include<cstdio>
#include<sstream>
#include<iomanip>
#include<assert.h>
#define loop(i,a,b) for(int i=a;i<b;i++) 
#define rep(i,a) loop(i,0,a)
#define pb push_back
#define all(in) in.begin(),in.end()
#define shosu(x) fixed<<setprecision(x)
using namespace std;
//kaewasuretyuui
typedef long long ll;
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
//#define mt make_tuple
//typedef tuple<double,int,double> tp;
//typedef vector<tp> vt;
template<typename A,typename B>bool cmin(A &a,const B &b){return a>b?(a=b,true):false;}
template<typename A,typename B>bool cmax(A &a,const B &b){return a<b?(a=b,true):false;}
const double PI=acos(-1);
const double EPS=1e-7;
Def inf = sizeof(Def) == sizeof(long long) ? 2e18 : 1e9;
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
class BIT{
	public:
	//[1,i]
	int n;
	vi bit;
//	int bit[MAZ_N+1];
	BIT(int size){
		n=size;
		bit=vi(n+1);
	}
	int query(int i){//sum
		int s=0;
		while(i>0){
			s+=bit[i];
			i-=i&-i;
		}
		return s;
	}
	void add(int i,int x){
		while(i<=n){
			bit[i]+=x;
			i+=i&-i;
		}
	}
};
int main(){
	int n,m;
	cin>>n>>m;
	BIT bit(n);
	rep(i,m){
		int a,b,c;
		cin>>a>>b>>c;
		if(a)cout<<bit.query(c)-bit.query(b-1)<<endl;
		else bit.add(b,c);
	}
}