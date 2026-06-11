#include<map>
#include<set>
#include<list>
#include<cmath>
#include<queue>
#include<stack>
#include<cstdio>
#include<string>
#include<vector>
#include<complex>
#include<cstdlib>
#include<cstring>
#include<numeric>
#include<sstream>
#include<iostream>
#include<algorithm>
#include<functional>

#define mp       make_pair
#define pb       push_back
#define all(x)   (x).begin(),(x).end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define REP(i,b,n) for(int i=b;i<n;i++)

using namespace std;

typedef    long long          ll;
typedef    unsigned long long ull;
typedef    vector<bool>       vb;
typedef    vector<int>        vi;
typedef    vector<vb>         vvb;
typedef    vector<vi>         vvi;
typedef    pair<int,int>      pii;
#define rad(x) (x*atan(1.0)*4.0/180.0)

const int INF=1<<29;
const double EPS=1e-9;

const int dx[]={1,0,-1,0},dy[]={0,-1,0,1};
int n;
void koch(double x1,double y1,double x4,double y4,int d){
	if(d==n){
		printf("%.5f %.5f\n",x4,y4);
		return ;
	}
	double x2 =(x4-x1)/3.0+x1;
	double y2 =(y4-y1)/3.0+y1;
	double x3=(x4-x1)*2/3.0+x1;
	double y3 =(y4-y1)*2.0/3.0+y1;
	double x = (x3-x2)*cos(rad(60.0)) - (y3-y2)*sin(rad(60.0)) + x2;
	double y = (x3-x2)*sin(rad(60.0)) + (y3-y2)*cos(rad(60.0)) + y2;
	koch( x1, y1, x2, y2, d+1 );
	koch( x2, y2, x,  y,  d+1 );
	koch( x,  y,  x3, y3, d+1 );
	koch( x3, y3, x4, y4, d+1 );
}

int main(){
	cin>>n;
	printf("%.5f %.5f\n",0.0,0.0);
	koch(0.0,0.0,100.0,0.0,0);
	return 0;
}