#include <iostream>
#include <cmath>
#include<iomanip>
struct Point
{
    double x ;
    double y ;


    Point( double x = 0 , double y = 0 )
        : x(x) , y(y) 
    {
    }

    void print()
    {
        std::cout << std::fixed << std::setprecision(10) << x << " " << y << std::endl ;
    }

} ;

void makeKoch( Point firstp , Point lastp, int n )
{
    if( n == 0 )
    {
        return  ;
    }

    Point s, u, t ;
    //ごちゃごちゃした計算
    s.x = ( 2*firstp.x + lastp.x ) / 3 ;
    s.y = ( 2*firstp.y + lastp.y ) / 3 ;
    t.x = ( firstp.x + 2*lastp.x ) / 3 ;
    t.y = ( firstp.y + 2*lastp.y ) / 3 ;

    u.x = ( t.x - s.x ) * std::cos( M_PI / 3 ) - ( t.y - s.y ) * std::sin( M_PI / 3 ) + s.x ;
    u.y = ( t.x - s.x ) * std::sin( M_PI / 3 ) + ( t.y - s.y ) * std::cos( M_PI / 3 ) + s.y ;

    makeKoch( firstp , s, n-1 ) ;
    s.print() ;
    makeKoch( s, u, n-1 ) ;
    u.print() ;
    makeKoch( u, t, n-1 ) ;
    t.print() ;
    makeKoch( t, lastp, n-1 ) ;
}

int main()
{
    int n ;
    std::cin >> n ;

    Point firstp( 0, 0 ) ;
    Point lastp( 100, 0 ) ;

    firstp.print() ;
    makeKoch( firstp , lastp , n ) ;
    lastp.print() ;

}

