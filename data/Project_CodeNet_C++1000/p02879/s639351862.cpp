#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
    int A, B; cin >> A >> B;
    if (A / 10 == 0 && B / 10 == 0) printf("%d\n", A*B);
    else printf("%d\n", -1);
}
