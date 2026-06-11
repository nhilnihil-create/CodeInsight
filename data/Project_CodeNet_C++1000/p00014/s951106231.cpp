#include <iostream>
using namespace std;

int area(int d){
    int x, y, sum, i;
    x = 600;
    y = d * d;
    sum = 0;
    i = 1;
    while(d * i <= 600 - d){
        sum += y * d;
        i++;
        y = (d * i) * (d * i);
    }
    return sum;
}

int main(void){
    int d;
    while(cin >> d) {
       cout << area(d) << endl;
    }
    return 0;
    
}

