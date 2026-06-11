#include <iostream>
 
int main() {
	int a,b,d,r;
    std::cin>>a;
    std::cin>>b;
    d=a/b;
    r=a%b;
    std::cout << d << " " << r << " ";
    printf("%.8lf\n", (double)a/(double)b );
    return 0;
}