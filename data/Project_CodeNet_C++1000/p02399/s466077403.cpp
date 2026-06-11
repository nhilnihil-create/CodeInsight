#include <iostream>
#include <stdio.h>

using namespace std;
 
int main(){
    int a, b, intans1, intans2;
    double fans;
    cin >> a >> b;

    if (a==0 || b==0) {
        return 0;
    }

    intans1 = a / b;
    intans2 = a % b;
    fans = static_cast<double>(a) / static_cast<double>(b);

    cout << intans1 << ' ' << intans2 << ' ';
    printf("%.5lf\n", fans);
    return 0;
}