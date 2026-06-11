#include <iostream>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <vector>
using namespace std;
int main() {
    int X; cin >> X;
    int G = lcm(360, X);
    printf("%d\n", G / X);
}
