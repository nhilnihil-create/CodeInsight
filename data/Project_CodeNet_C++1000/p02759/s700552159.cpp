#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
    int N;
    cin >> N;
    if (N % 2 != 0) N++;
    cout << N / 2 << endl;
}
