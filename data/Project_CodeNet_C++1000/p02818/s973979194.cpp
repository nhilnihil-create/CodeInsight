#include <iostream>
#include<string>
using namespace std;
using ulli = unsigned long long int;
using lli = long long int;

int main() {
    lli a, b, k;
    cin >> a >> b >> k;
    cout << ((a - k >= 0) ? a - k : 0) << " " << ((a - k >= 0) ? b : ((a + b - k >= 0) ? a + b - k : 0)) << endl;
    return 0;
}