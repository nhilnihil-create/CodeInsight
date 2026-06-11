#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>

using namespace std;
static const double pi = 3.141592653589793;

typedef struct __zahyou
{
        double x;
        double y;
} zahyou_t;

zahyou_t calc_spoint( zahyou_t p1, zahyou_t p2 )
{
        zahyou_t s;
        s.x = ( 2*p1.x + 1*p2.x ) / 3;
        s.y = ( 2*p1.y + 1*p2.y ) / 3;

        return s;
}

zahyou_t calc_tpoint( zahyou_t p1, zahyou_t p2 )
{
        zahyou_t t;
        t.x = ( 1*p1.x + 2*p2.x ) / 3;
        t.y = ( 1*p1.y + 2*p2.y ) / 3;

        return t;
}

zahyou_t calc_upoint( zahyou_t s, zahyou_t t )
{
        zahyou_t u;
        u.x = ( t.x - s.x ) * cos( pi / 3 ) -
                ( t.y - s.y ) * sin( pi / 3 ) + s.x;
        u.y = ( t.x - s.x ) * sin( pi / 3 ) +
                ( t.y - s.y ) * cos( pi / 3 ) + s.y;
        return u;
}

void printpoint( zahyou_t p )
{
        cout << showpoint << p.x << " "
                << showpoint << p.y << endl;
}

int kock( int n, zahyou_t p1, zahyou_t p2 )
{
        if ( n == 0 )
                return 0;

        zahyou_t s = calc_spoint( p1, p2 );
        zahyou_t t = calc_tpoint( p1, p2 );
        zahyou_t u = calc_upoint( s, t );

        kock( n-1, p1, s );
        printpoint( s );
        kock( n-1, s, u );
        printpoint( u );
        kock( n-1, u, t );
        printpoint( t );
        kock( n-1, t, p2 );

        return 0;
}

int main()
{
        zahyou_t p1, p2;
        p1.x = 0, p1.y = 0;
        p2.x = 100, p2.y = 0;

        int set_num;
        cin >> set_num;
        printpoint( p1 );
        kock( set_num, p1, p2 );
        printpoint( p2 );

        return 0;
}