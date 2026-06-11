#include<iostream>
using namespace std;

int main() {
    int x;
    cin >> x;

    int a = x / 500;
    int b = (x - a * 500) / 5;
    cout << a * 1000 + b * 5<< endl;
}