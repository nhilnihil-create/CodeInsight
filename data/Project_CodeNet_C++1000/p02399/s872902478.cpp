#include <iostream>
#include <iomanip>

int main()
{
    int a, b;
    std::cin >> a >> b;

    const int d = a / b;
    const int r = a % b;
    const double f = a / static_cast<double>( b );

    std::cout.setf( std::ios_base::fixed,std::ios_base::floatfield );
    std::cout << std::setprecision( 15 )
        << d << " " << r << " " << f
        << std::endl;

    return 0;
}