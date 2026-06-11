#include <math.h>

#include <cmath>
#include <iostream>
using namespace std;
int main() {
    int a,keta1,keta2,keta3;
    cin >> a;
    keta1 = a - (a / 10 * 10);
    keta2 = ((a - (a / 100 * 100) - keta1) / 10);
    keta3 = a / 100;
    if(keta1==7||keta2==7||keta3==7){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
    return 0;
}