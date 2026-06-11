#include<cstdio>
#include<cmath>
double rota = M_PI * 60.0 / 180.0;//旋转的角度
struct Point{
	double x,y;
};

void printPoint(Point* p){
	printf("%.8f %.8f\n", p->x,p->y);
}

void koch(int n, Point *p1,Point *p2){
	if(n-- == 0)return;
	Point koch1,koch2,koch3;
	koch1.x = (2 * p1 -> x + p2 -> x) / 3;
	koch1.y = (2 * p1 -> y + p2 -> y) / 3;
	koch3.x = (2 * p2 -> x + p1 -> x) / 3;
	koch3.y = (2 * p2 -> y + p1 -> y) / 3;
	koch2.x = (koch3.x - koch1.x) * cos(rota) - (koch3.y - koch1.y) * sin(rota) + koch1.x;
	koch2.y = (koch3.x - koch1.x) * sin(rota) + (koch3.y - koch1.y) * cos(rota) + koch1.y;
	koch(n, p1, &koch1);
	printPoint(&koch1);
	koch(n, &koch1, &koch2);
	printPoint(&koch2);
	koch(n, &koch2, &koch3);
	printPoint(&koch3);
	koch(n, &koch3, p2);
}

int main(){
	int n;
	Point p1,p2;
	p1.x=0.0;p1.y=0.0;
	p2.x=100.0;p2.y=0.0;
	scanf("%d", &n);
	printPoint(&p1);
	koch(n,&p1,&p2);
	printPoint(&p2);
	scanf("%d", &n);
	return 0;
}
