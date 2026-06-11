#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
    int a, b, c; cin >> a >> b >> c;
    if (a + b + c >= 22) printf("%s\n", "bust");
    else printf("%s\n", "win");
}
