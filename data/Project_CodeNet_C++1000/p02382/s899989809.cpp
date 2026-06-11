#include<iostream>
using namespace std;
#include<cmath>
#include<stdlib.h>
#include<algorithm>
#include<iomanip>

int main() {
        int n;
        double x[100], y[100], one, two, three, inf, maxD, temp;
        cin >> n;
        one = 0;
        two = 0;
        three = 0;
        for(int i = 0; i < n; i++) {
                cin >> x[i];
        }
        for(int i = 0; i < n; i++) {
                cin >> y[i];
        }
        inf = abs(x[0] - y[0]);
        for(int i = 0; i < n; i++) {
                temp = abs(x[i] - y[i]);
                one += abs(temp);
                two += pow(temp, 2);
                three += pow(abs(temp), 3);
                inf = max(inf, abs(temp));
        }
        cout << fixed << setprecision(8);
        cout << one << endl;
        cout << sqrt(two) << endl;
        cout << cbrt(three) << endl;
        cout << inf << endl;
        return 0;
}