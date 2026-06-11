#include <cstdio>
#include <cmath>

#define PI 3.14159265

using namespace std;
/*  u
p s   t q
*/



void koch(double px, double py, double qx, double qy, int times) {
	
	if(times > 0) {

		//sの座標を求める
		double sx = (2 * px + qx) / 3;
		double sy = (2 * py + qy) / 3;

		//tの座標を求める
		double tx = (px + 2 * qx) / 3;
		double ty = (py + 2 * qy) / 3;

		//uの座標を求める(sを30°回転させる)
		double ux = (tx - sx) * cos(PI / 3) - (ty - sy) * sin(PI / 3) + sx;
		double uy = (tx - sx) * sin(PI / 3) + (ty - sy) * cos(PI / 3) + sy;

		//pとsを端点とする
		koch(px, py, sx, sy, times - 1);

		//sを表示
		printf("%f %f\n", sx, sy);

		//sとuを端点とする
		koch(sx, sy, ux, uy, times - 1);

		//uを表示
		printf("%f %f\n", ux, uy);

		//uとtを端点とする
		koch(ux, uy, tx, ty, times - 1);

		//tを表示
		printf("%f %f\n", tx, ty);

		//tとqを端点とする
		koch(tx, ty, qx, qy, times - 1);
	}
}

int main(){
	int n;
	scanf("%d", &n);
	printf("%f %f\n", 0.00000000, 0.00000000);
	koch(0, 0, 100, 0, n);
	printf("%f %f\n", 100.00000000, 0.00000000);
	return 0;
}
