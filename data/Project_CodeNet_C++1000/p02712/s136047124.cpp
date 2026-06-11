#include <iostream>
using namespace std;
int main() {
    long long n;
    cin >> n;
    long long threesum = 0;
    threesum = 3*((n/3)*((n/3) + 1)/2);
    long long fivesum = 0;
    fivesum = 5*((n/5)*((n/5) + 1)/2);
    long long fifsum = 15*((n/15)*((n/15) + 1)/2);
    long long total = n*(n + 1)/2;
    cout << total - fivesum - threesum + fifsum << endl;
}
