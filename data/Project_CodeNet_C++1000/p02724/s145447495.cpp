#include <bits/stdc++.h>
using namespace std;

int main() {
    int X;
    cin >> X;
    int happy;
    happy = X / 500 * 1000;
    int nokori = X % 500;
    happy += nokori / 5 * 5;
    cout << happy << endl;
}