#include <bits/stdc++.h>
using namespace std;

#define PI 3.1415926535
#define X real()
#define Y imag()

typedef complex<double> point;
typedef point vec;

vec rotate(vec v, double r) {
	return v*vec(cos(r), sin(r));
}

void f(int n,point p,point q){
	if(n--==0){
		cout<<setprecision(6)<<fixed<<p.X<<" "<<p.Y<<endl;
		return;
	}
	vec v=(q-p)/(point)3;
	point r=p+v;
	point s=r+rotate(v,PI/3);
	point t=q-v;
	f(n,p,r);
	f(n,r,s);
	f(n,s,t);
	f(n,t,q);
	return;
}

int main(){
	int n;
	cin>>n;
	f(n,(point)0,(point)(100));
	cout<<100<<" "<<0<<endl;
}