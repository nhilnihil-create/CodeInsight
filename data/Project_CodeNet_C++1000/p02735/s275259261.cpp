//#define _DEBUG
#include "bits/stdc++.h"
#define CHOOSE(a) CHOOSE2 a
#define CHOOSE2(a0,a1,a2,a3,a4,x,...) x
#define debug_1(x1) cout<<#x1<<": "<<x1<<endl
#define debug_2(x1,x2) cout<<#x1<<": "<<x1<<", "#x2<<": "<<x2<<endl
#define debug_3(x1,x2,x3) cout<<#x1<<": "<<x1<<", "#x2<<": "<<x2<<", "#x3<<": "<<x3<<endl
#define debug_4(x1,x2,x3,x4) cout<<#x1<<": "<<x1<<", "#x2<<": "<<x2<<", "#x3<<": "<<x3<<", "#x4<<": "<<x4<<endl
#define debug_5(x1,x2,x3,x4,x5) cout<<#x1<<": "<<x1<<", "#x2<<": "<<x2<<", "#x3<<": "<<x3<<", "#x4<<": "<<x4<<", "#x5<<": "<<x5<<endl
#ifdef _DEBUG
#define debug(...) CHOOSE((__VA_ARGS__,debug_5,debug_4,debug_3,debug_2,debug_1,~))(__VA_ARGS__)
#else
#define debug(...)
#endif
#define rep(index,num) for(int index=0;index<(int)num;index++)
#define rep1(index,num) for(int index=1;index<=(int)num;index++)
#define brep(index,num) for(int index=(int)num-1;index>=0;index--)
#define brep1(index,num) for(int index=(int)num;index>0;index--)
#define scan(argument) cin>>argument
#define prin(argument) cout<<argument<<endl
#define kaigyo cout<<endl
#define eps 1e-7
#define mp(a1,a2) make_pair(a1,a2)
#define ALL(a) (a).begin(),(a).end()
#define rALL(a) (a).rbegin(),(a).rend()
typedef long long ll;
typedef long double ld;
using namespace std;
typedef pair<ll,ll> pll;
typedef pair<int,int> pint;
typedef vector<int> vint;
typedef vector<ll> vll;
typedef vector<pint> vpint;
typedef vector<pll> vpll;
ll INFl=(ll)1e+18+1;
int INF=1e+9+1;
int main(){
	int H,W;
	char s[103][103];
	int mind[103][103];
	scan(H>>W);
	fill(mind[0],mind[103],INF);
	rep(i,H){
		scan(s[i]);
	}
	if(s[0][0]=='.') mind[0][0]=0;
	else mind[0][0]=1;
	rep(k,H+W-2){
		rep(j,W){
			int i=k-j;
			if(0<=j&&j<W&&0<=i&&i<H){
				if(i<H-1){
					if(s[i][j]=='.'&&s[i+1][j]=='#') mind[i+1][j]=min(mind[i+1][j],mind[i][j]+1);
					else mind[i+1][j]=min(mind[i+1][j],mind[i][j]);
				}
				if(j<W-1){
					if(s[i][j]=='.'&&s[i][j+1]=='#') mind[i][j+1]=min(mind[i][j+1],mind[i][j]+1);
					else mind[i][j+1]=min(mind[i][j+1],mind[i][j]);
				}
			}
		}
	}
	prin(mind[H-1][W-1]);
	return 0;
}
