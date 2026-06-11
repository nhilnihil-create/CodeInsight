#include <iostream>
#include <math.h>
#include <ctype.h>

using namespace std;

int main() {

    int n;
    cin>>n;

    n%=10;

    switch(n) {
        case 0:
        case 1:
        case 6:
        case 8: cout<<"pon"; break;
        case 2:
        case 4:
        case 5:
        case 7: 
        case 9: cout<<"hon"; break;
        case 3: cout<<"bon"; break;
    }

    

}

