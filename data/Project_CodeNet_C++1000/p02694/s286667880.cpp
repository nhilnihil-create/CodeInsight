#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>

#define PI 3.14159265358979323846
using namespace std;

int main() {
    long long x, count = 0;
    cin >> x;
    long long balance = 100;
    while (balance < x) {
        balance += balance / 100;
        count++;
    }

    cout << count << endl;
}