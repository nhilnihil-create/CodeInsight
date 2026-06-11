#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define fx(x) fixed<<setprecision(x)

vector<double> v(1000,0);
double exp(double x){
	if(v[x]) return v[x];
	double ans=0;
	for(int i=1; i<=x; i++) ans+=i*(1/x);
	v[x]=ans;
	return ans;
}

int main(){
	int n,k; cin>>n>>k;
	vector<int> p(n);
	rep(i,n) cin>>p[i];
	
	vector<double> e(n);
	rep(i,n) e[i]=exp(p[i]);
  
	vector<double> r(n+1,0);
	rep(i,n){
		r[i+1]=r[i]+e[i];
	}
	
	double mx=0;
	for(int i=0; i<=n-k; i++){
		double sum=(r[i+k]-r[i]);
		mx=max(mx,sum);
	}
	cout<<fx(10)<<mx<<endl;
}
