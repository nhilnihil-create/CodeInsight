#include <iostream>
#include <math.h>
#include <string>
using namespace std;

int main()
{
    int a , b , c , dif ;
    cin >> a >> b >> c ;
    dif = a - b ;
    c -= dif ;
    if (c < 0){
        cout << 0 ;
    }
    else {
        cout << c ;
    }
    return 0;
}
