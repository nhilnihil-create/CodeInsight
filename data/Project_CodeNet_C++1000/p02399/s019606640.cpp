#include <stdio.h>
#include <iostream>

using namespace std;

int main()
{
    long int a = 0;
    long int b = 0;
    
    cin >> a >> b;
    
    printf("%d %d %f\n",a/b,a%b,a/(double)b);
    
    return 0;
}
