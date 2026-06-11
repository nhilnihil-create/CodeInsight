#include <iostream>
#include <cmath>
#include <stdio.h>

using namespace std;

static const double pi = 3.141592653589793;
typedef struct _point {
	double x;
	double y;
} point_t;

void print_point(point_t p1) {
	fprintf( stdout, "%.8f %.8f\n", p1.x, p1.y );
}

void koch(int number, point_t p1, point_t p2){
	if ( number == 0 ) {
		return;
	}

	point_t s, t, u;
	s.x = (2*p1.x+p2.x) / 3;
	s.y = (2*p1.y+p2.y) / 3;
	t.x = (p1.x+2*p2.x) / 3;
	t.y = (p1.y+2*p2.y) / 3;
	u.x = (t.x-s.x)*cos(pi/3)-(t.y-s.y)*sin(pi/3)+s.x;  
	u.y = (t.x-s.x)*sin(pi/3)+(t.y-s.y)*cos(pi/3)+s.y; 
	koch( number-1, p1, s );
	print_point( s );
	koch( number-1, s, u );
	print_point( u );
	koch( number-1, u, t );
	print_point( t );
	koch( number-1, t, p2 );
}

int main() {
	point_t p1, p2;
	p1.x = 0.0000;
	p1.y = 0.0000;
	p2.x = 100.0000;
	p2.y = 0.0000;
	int n;
	cin >> n;

	print_point( p1 );
	koch( n, p1, p2 );
	print_point( p2 );
	return 0;
}

