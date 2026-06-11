#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
double pi=3.141592653589793;

int main(){
	double a,b,x;
	cin>>a>>b>>x;
	double s=x/a;//面積
	double rad;
	if(a*b/2<=s){//半分あるかどうか
		double w=(a*b-s)*2/a;
		rad = atan2(w,a);
	}else{
		double w=s*2/b;
		rad = atan2(b,w);
	}
	cout<<fixed<<setprecision(8)<<rad/pi*180<<endl;
}