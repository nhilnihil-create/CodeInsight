#include <stdlib.h>
#include <stdio.h>
#include <iostream>
using namespace std;

struct point2D
{
	double x, y;
	point2D(){
		x = (double)0.0;
		y = (double)0.0;
	}
	point2D(double x, double y){
		this->x = x;
		this->y = y;
	}
	point2D(point2D *p){
		x = p->x;
		y = p->y;
	}
};
void koch(point2D *start, point2D *end, int d);
void print_point2D(point2D *p);
int main(){
	int n;

	cin >> n;

	point2D *start = new point2D((double)0.0, (double)0.0);
	point2D *end = new point2D((double)100.0, (double)0.0);
	print_point2D(start);
	koch(start, end, n);
	return 0;
}

void koch(point2D *start, point2D *end, int d){
	point2D *p1 = new point2D( (2*start->x +   end->x)/3, (2*start->y +   end->y)/3);
	point2D *p3 = new point2D( (  start->x + 2*end->x)/3, (  start->y + 2*end->y)/3);

	point2D *vec_p1_to_p3 = new point2D(p3->x - p1->x, p3->y - p1->y);
	point2D *vec_p1_to_p2 = new point2D( 0.5 * vec_p1_to_p3->x - 0.86602540378 * vec_p1_to_p3->y,
										0.86602540378 * vec_p1_to_p3->x + 0.5 * vec_p1_to_p3->y);
	point2D *p2 = new point2D(p1->x + vec_p1_to_p2->x, p1->y + vec_p1_to_p2->y);
	if(d <= 0){
		print_point2D(end);
		return;
	}
	koch(start, p1, d-1);
	koch(p1, p2, d-1);
	koch(p2, p3, d-1);
	koch(p3, end, d-1);
}
void print_point2D(point2D *p){
	printf("%.8lf %.8lf\n", p->x, p->y);
}