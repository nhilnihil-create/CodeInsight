#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

int main(){

        double x1,y1,x2,y2,answer;

        cin >> x1 >> y1 >> x2 >>y2;
        answer = sqrt(pow((x1 - x2),2) + pow((y1 - y2),2));
        cout << fixed << setprecision(8) << answer << endl;


        return 0;
}