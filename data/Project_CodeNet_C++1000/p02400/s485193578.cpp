#include <iostream>
#include <iomanip>
#include <cmath>

double Area( double r )
{
    return r * r * M_PI;
}
double Circumference( double r )
{
    return 2 * r * M_PI;
}

int main()
{
    double r;
    std::cin >> r;

    std::cout.setf( std::ios_base::fixed,std::ios_base::floatfield );
    std::cout << std::setprecision( 15 )
        << Area( r ) << " " << Circumference( r )
        << std::endl;

    return 0;
}