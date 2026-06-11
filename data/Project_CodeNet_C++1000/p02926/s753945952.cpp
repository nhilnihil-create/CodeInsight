// #pragma GCC target("avx2")  // CPU 処理並列化
// #pragma GCC optimize("O3")  // CPU 処理並列化
// #pragma GCC optimize("unroll-loops")  // 条件処理の呼び出しを減らす
#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<queue>
#include<deque>
#include<stack>
#include<string>
#include<string.h>
#include<vector>
#include<set>
#include<map>
#include<bitset>
#include<stdlib.h>
#include<cassert>
#include<time.h>
#include<bitset>
#include<numeric>
using namespace std;
const long long mod=1000000007;
const long long inf=mod*mod;
const long long d2=(mod+1)/2;
const double EPS=1e-10;
const double INF=1e+10;
const double PI=acos(-1.0);
const int C_SIZE = 3121000;
namespace{
	long long fact[C_SIZE];
	long long finv[C_SIZE];
	long long inv[C_SIZE];
	long long Comb(int a,int b){
	 	if(a<b||b<0)return 0;
	 	return fact[a]*finv[b]%mod*finv[a-b]%mod;
	}
	void init_C(int n){
		fact[0]=finv[0]=inv[1]=1;
		for(int i=2;i<n;i++){
			inv[i]=(mod-(mod/i)*inv[mod%i]%mod)%mod;
		}
		for(int i=1;i<n;i++){
			fact[i]=fact[i-1]*i%mod;
			finv[i]=finv[i-1]*inv[i]%mod;
		}
	}
	long long pw(long long a,long long b){
		if(a<0LL)return 0;
		if(b<0LL)return 0;
		long long ret=1;
		while(b){
			if(b%2)ret=ret*a%mod;
			a=a*a%mod;
			b/=2;
		}
		return ret;
	}
	int ABS(int a){return max(a,-a);}
	long long ABS(long long a){return max(a,-a);}
	double ABS(double a){return max(a,-a);}
	int sig(double r) { return (r < -EPS) ? -1 : (r > +EPS) ? +1 : 0; }
}
// ここから編集しろ
int x[110];
int y[110];
vector<double>th;
int main(){
	int a;scanf("%d",&a);for(int i=0;i<a;i++)scanf("%d%d",x+i,y+i);
	for(int i=0;i<a;i++){
		if(x[i]==0&&y[i]==0)continue;
		double tr=atan2(y[i],x[i]);
		th.push_back(tr);
		for(int j=0;j<a;j++){
			if(i==j)continue;
			if(x[j]==0&&y[j]==0)continue;
			double ts=atan2(y[j],x[j]);
			th.push_back((tr+ts)/2);
		}
	}
	double ret=0;
	for(int i=0;i<th.size();i++){
		double X=0;
		double Y=0;
		double vx=cos(th[i]);
		double vy=sin(th[i]);
		for(int j=0;j<a;j++){
			double prod=vx*x[j]+vy*y[j];
			if(prod>=0){
				X+=x[j];
				Y+=y[j];
			}
		}
		ret=max(ret,sqrt(X*X+Y*Y));
	}
	printf("%.12f\n",ret);
}