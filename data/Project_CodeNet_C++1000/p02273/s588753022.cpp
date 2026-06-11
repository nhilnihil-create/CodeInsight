#include<bits/stdc++.h>
using namespace std;
typedef struct {
	double x,y;
}point;
void koch_curve(int,point,point);
int main(void){
	point p1,p2;
	int num;
	cin >> num;

	p1.x = 0;
	p1.y = 0;
	p2.x = 100;
	p2.y = 0;

	cout.precision(8);
	cout << p1.x <<" "<< p1.y << endl;
	koch_curve(num,p1,p2);
	cout << p2.x <<" "<< p2.y << endl;
	return 0;
}
void koch_curve(int num,point p1,point p2){
	if(num==0) return;

	point s,t,u;
	double theta =  1.0 / 3  * M_PI;

	//内分点の公式を用いて計算
	s.x = (2 * p1.x + 1 * p2.x) / 3;
	s.y = (2 * p1.y + 1 * p2.y) / 3;
	t.x = (1 * p1.x + 2 * p2.x) / 3;
	t.y = (1 * p1.y + 2 * p2.y) / 3;

	//原点以外の場合の点の回転の行列式の公式を用いて計算
	u.x = (t.x - s.x) * cos(theta) - (t.y - s.y) * sin(theta) + s.x;
	u.y = (t.x - s.x) * sin(theta) + (t.y - s.y) * cos(theta) + s.y;
	
	koch_curve(num-1,p1,s);
	cout << s.x << " " << s.y << endl;
	koch_curve(num-1,s,u);
	cout << u.x << " " << u.y << endl;
	koch_curve(num-1,u,t);
	cout << t.x << " " << t.y << endl;
	koch_curve(num-1,t,p2);

}
	




	