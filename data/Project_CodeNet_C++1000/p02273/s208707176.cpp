#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>
#include<cmath>
#include<climits>
#include<string>
#include<set>
#include<numeric>
#include<map>
#include<iostream>
using namespace std;
#define rep(i,n) for(int i = 0;i<((int)(n));i++)
#define reg(i,a,b) for(int i = ((int)(a));i<=((int)(b));i++)
#define irep(i,n) for(int i = ((int)(n)-1);i>=0;i--)
#define ireg(i,a,b) for(int i = ((int)(b));i>=((int)(a));i--)
typedef long long ll;
typedef pair<ll, ll> mp;

void koch(int N,double x1,double y1,double x5,double y5){//
	if(N==0){
		cout<<x1<<" "<<y1<<endl;
	}else{
		double x2=(x1*2+x5)/3;
		double y2=(y1*2+y5)/3;
		double x3=x2+cos(-M_PI/3)*(x2-x1)+sin(-M_PI/3)*(y2-y1);
		double y3=y2-sin(-M_PI/3)*(x2-x1)+cos(-M_PI/3)*(y2-y1);
		double x4=(x1+x5*2)/3;
		double y4=(y1+y5*2)/3;
		koch(N-1,x1,y1,x2,y2);
		koch(N-1,x2,y2,x3,y3);
		koch(N-1,x3,y3,x4,y4);
		koch(N-1,x4,y4,x5,y5);
	}
}

int main(void){
	int n;
	cin>>n;
	koch(n,0,0,100,0);
	cout<<100<<" "<<0<<endl;
	return 0;
}