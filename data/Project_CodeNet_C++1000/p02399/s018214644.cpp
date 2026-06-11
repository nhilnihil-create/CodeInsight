#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <iomanip>

using namespace std;

int main(){

        int a,b,d,r;
        double f;
        cin >> a >> b;

        d = a / b;
        r = a % b;
        f = (double)a / b;

        cout << d << " " << r << " ";
        cout << fixed << setprecision(8) << f << "\n";

        return 0;
}