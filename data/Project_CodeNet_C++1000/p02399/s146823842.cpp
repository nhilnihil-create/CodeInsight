#include<iostream>
using namespace std;
int main() {
    int a, b;
    cin >> a >> b;
    int d = a / b;
    int r = a % b;
    double f = ((double) a / (double) b) * 100000000;
    cout << d << " "<< r << " " << fixed << f/100000000 << endl;
}
