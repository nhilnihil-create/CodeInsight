#include <iostream>
#include <iomanip>
using namespace std;
int main() {
cin.tie(0);
ios::sync_with_stdio(false);
int a, b;
cin >> a >> b;
int d = a / b;
int r = a % b;
double f = (double) a / (double) b;
cout << d << " " << r << " " << fixed << setprecision(8) << f << "\n";
}