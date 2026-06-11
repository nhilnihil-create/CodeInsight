#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
using namespace std;


int main() {
    int i, j, num, start, end, c;
    double a, b, rad, s[1000], mean, dev;

    cin >> num;
    while(num!=0){

        mean=0.0;
        for(i=0;i<num;i++){
            cin >> s[i];
            mean = mean + s[i];
        }
        mean = mean / num;

        dev=0.0;
        for(i=0;i<num;i++){
            dev = dev + (s[i]-mean)*(s[i]-mean);
        }
        dev = sqrt(dev/num);

        cout << fixed <<setprecision(10) << dev << endl;

        cin >> num;
    }

    return 0;
}
