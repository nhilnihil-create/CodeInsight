#include<bits/stdc++.h>
 using namespace std;
 const long double PI = acos(-1);
 
 int main(){
 	int A,B,H,M;
 	//入力受け取り
 	cin >> A >> B >> H >> M;
 	long double theta_H=0,theta_M=0;
 	long double Hx=0,Hy=0;
 	long double Mx=0,My=0;
 	long double dx=0,dy=0;
 	//角度を求める
 	theta_M = (long double)(M/60.0)*2*PI;
 	theta_H = ((long double)(H/12.0)+(long double)(M/60.0)/12.0)*2*PI;
 	//座標を求める
 	Hx=(A*cos(theta_H)); Hy=(A*sin(theta_H));
 	Mx=(B*cos(theta_M)); My=(B*sin(theta_M));
 	//座標間の差を求める
 	dx=(Hx-Mx);dy=(Hy-My);
 	//ユークリッド距離を求める
 	long double ans=sqrt(dx*dx+dy*dy);
 	
 	cout << fixed << setprecision(20);
 	cout << ans << "\n";
 }