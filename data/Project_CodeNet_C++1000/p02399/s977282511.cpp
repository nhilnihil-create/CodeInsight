#include <iostream>
#include <stdio.h>

using namespace std;
int main (int argc, const char * argv[])
{
    int a,b;
    cin >>a >>b;
    double f1,f2;
    f1=a/b;
    f2=(double)a/b;
    //cout << a/b<<" "<<a%b<<" "<<a/b<<endl;
    printf("%.0f ", f1 );
     printf("%.1d ", a%b );
    printf("%.8f\n", f2 );

    // insert code here...
   // std::cout << "Hello, World!\n";
    return 0;
}