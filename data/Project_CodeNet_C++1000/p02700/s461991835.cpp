#include<iostream>
#include<cmath>
using namespace std;

int main() {
    float A, B, C, D;
    cin >> A >> B >> C >> D;

    if (ceil(C / B) <= ceil(A / D)) cout << "Yes" << endl;
    else cout << "No" << endl;
}