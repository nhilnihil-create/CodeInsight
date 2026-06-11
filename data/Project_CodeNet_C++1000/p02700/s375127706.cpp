#include <cmath>
#include <iostream>
using namespace std;

int main() {
    float a, b, c, d;
    cin >> a >> b >> c >> d;

    string answer = (ceil(c / b) <= ceil(a / d)) ? "Yes" : "No";
    cout << answer;
}