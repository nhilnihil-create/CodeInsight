#include <bits/stdc++.h>
using namespace std;
typedef long long ll;



double a, b, x;

int main(){
	cin >> a >> b >> x;
	x /= a;
	
	double th = 0.0;
	if ( x >= a*b*0.5 ){
		// 断面が四角形の内にこぼれる
		double y = a*b-x; // 容器の水が入っていない部分
		
		/*
		  b' = r sin(th)
		  a = r cos(th)
		  a * b' * 0.5 = y
		  th = ?
		  
		  b' = 2y/a
		  b'/a = tan(th)
		  
		  2y/a^2 = tan(th)
		  th = arctan( 2y/a^2 )
		*/
		
		th = atan(2.0*y/(a*a));
	}
	else {
		// 断面が三角形になってからこぼれる
		/*
		  b = r sin(th)
		  a' = r cos(th)
		  a' * b * 0.5 = x
		  th = ?
		  
		  a' = 2x/b
		  b/a' = tan(th)
		  b = 2x/b * tan(th)
		  
		  th = arctan( b^2 / 2x )
		*/
		th = atan(b*b*0.5/x);
	}
	
	cout << std::setprecision(8) << (th*360.0/(2.0*M_PI)) << endl;
	
	return 0;
}

