#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
    int A, B, C; cin >> A >> B >> C;
    if (C + B <= A) printf("%d\n", 0);
    else printf("%d\n", (B + C) - A);
}
