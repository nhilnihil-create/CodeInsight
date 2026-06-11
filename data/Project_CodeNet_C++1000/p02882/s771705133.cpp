//Author: Fuadul Hasan(fuadul202@gmail.com)
#include<bits/stdc++.h>
using namespace std;

#define ll long long
const int N   = 2e5 + 5;
#define Pi atan(1)*4

float get(int x,int y,int z){
	int volume = x*x*y;
	float ans = 0.0;
	if(z < volume/2){
		float d = (x*y*y)/(2.0 *z);
		ans = atan(d);
	}else{
		z = volume - z;
		float d = (2*z)/(float)(x*x*x);
		ans = atan(d);
	}
	//cout<<Pi<<endl;
	ans = ((ans*180)/(Pi));
	//ans = ((ans*180)/Pi);
	return ans;
}

int main(){
	
	int a,b,n;
	cin>>a>>b>>n;

	cout<<setprecision(20)<<get(a,b,n)<<endl;

	return 0;
}