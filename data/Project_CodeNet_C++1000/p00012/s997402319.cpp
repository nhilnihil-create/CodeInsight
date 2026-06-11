#include<iostream>
#include<math.h>
using namespace std;

struct Pos{
	double x,y;
};

Pos VSub(Pos pos1,Pos pos2){
	pos1.x -= pos2.x;
	pos1.y -= pos2.y;
	return pos1;
}

Pos Rotate(Pos v,double ang){
	double t;
	t = v.y;
	v.y = v.y*cos(ang)+v.x*sin(ang);
	v.x = v.x*cos(ang)-t*sin(ang);
	return v;
}
int main(){
	Pos point[4];	//point[3]:ten
	char *c[200];
	int i,cor = 0;
	while(cin >> point[0].x){
		cin >> point[0].y;
		for(i = 1;i < 4;i++){
			cin >> point[i].x >> point[i].y;
		}
		Pos v[6];
		double at[6];
		for(i = 0;i < 3;i++){
			v[i] = VSub(point[(i+1)%3],point[i]);
			v[i+3] = VSub(point[3],point[i]);
		}
		for(i = 0;i < 3;i++){
			at[i] = atan2(v[i].y,v[i].x);
			v[i+3] = Rotate(v[i+3],-at[i]);
			at[i+3] = atan2(v[i+3].y,v[i+3].x);
		}
		if(at[3] * at[4] > 0 && at[4]*at[5] > 0)
			c[cor] = "YES";
		else
			c[cor] = "NO";
		cor++;
	}
	for(i = 0;i < cor;i++)
		cout << c[i] << endl;
}