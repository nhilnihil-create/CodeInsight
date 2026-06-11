#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
    int A, B; cin >> A >> B;
    int ans = A - B * 2;
    if (ans < 0) printf("%d\n", 0);
    else printf("%d\n", ans);
}
