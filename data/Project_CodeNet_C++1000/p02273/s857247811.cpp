#include <stdio.h>
#include <math.h>
#include <utility>

using namespace std;
typedef pair<double, double> Point;

int n;

const double cos60 = cos( M_PI / 3.0 );
const double sin60 = sin( M_PI / 3.0 );

void solve( int i, Point p0, Point p1 );



int main()
{
    Point p0, p1;
    p0.first  = 0.0;
    p0.second = 0.0;
    p1.first  = 100.0;
    p1.second = 0.0;

    scanf("%d", &n);

    printf("%.10lf %.10lf\n", 0.0, 0.0);

    solve( 0, p0, p1 );

    return 0;
}




void solve( int i, Point p0, Point p1 )
{
    if ( i == n ) {
	printf("%.10lf %.10lf\n", p1.first, p1.second);
    }
    else {
	Point np0, np1, np2;
	double vx = p1.first - p0.first;
	double vy = p1.second - p0.second;
	double ex = vx / 3.0;
	double ey = vy / 3.0;
	np0.first   = p0.first  + ex;
	np0.second  = p0.second + ey;
	np1.first   = np0.first  + cos60 * ex - sin60 * ey;
	np1.second  = np0.second + sin60 * ex + cos60 * ey;
	np2.first   = p0.first  + 2.0 * ex;
	np2.second  = p0.second + 2.0 * ey;
	solve( i + 1, p0,  np0 );
	solve( i + 1, np0, np1 );
	solve( i + 1, np1, np2 );
	solve( i + 1, np2, p1 );
    }
}