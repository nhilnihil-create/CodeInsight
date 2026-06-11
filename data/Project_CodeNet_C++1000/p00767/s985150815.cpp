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
//typedef tuple<int,string> tp;
//typedef vector<tp> vt;
const double PI=acos(-1);
const double EPS=1e-7;
const int inf=1e9;
const ll INF=2e18;
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
int main(){
	int a,b;
	while(cin>>a>>b,a){
		int d=a*a+b*b;
		int outa=inf,outb=inf,outd=inf;
		loop(i,1,151)loop(j,i+1,151){
			int nd=i*i+j*j;
			if(i==a&&j==b)continue;
			if(nd==d&&i<a)continue;
			if(d>nd)continue;
			if(outd==nd){
				if(outa>i){
					outa=i;
					outb=j;
					outd=nd;
				}//16+49=65 1+64=65
			}else if(outd>nd){
				outa=i;
				outb=j;
				outd=nd;
			}
		}
		cout<<outa<<" "<<outb<<endl;
	}
}