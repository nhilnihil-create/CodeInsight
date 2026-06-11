#include<bits/stdc++.h>
 using namespace std;
 
 const long double PI = (acos(-1));
 
 int main(){
 	int A,B,H,M;
 	long double ans=0;
 	long double rad=0;
 	long double theta_m=0;
 	long double theta_h=0;
 	//入力受け取り
 	cin >> A >> B >> H >> M;
 	//分針、時針を円の割り合になおす
 	theta_m = (long double)M/60.0;
 	theta_h = (long double)H/12.0 + ((long double)M/60.0/12.0);
 	//内角の大きさを求めラジアンになおす
 	rad=(theta_h-theta_m)*2*PI;
 	//第二余弦定理に適用する
 	ans=A*A+B*B-2*A*B*cos(rad);
 	//ansは2乗の状態なのでrootを求める
 	ans=sqrt(ans);
 	cout << fixed << setprecision(20);
 	cout << ans << "\n";
 }