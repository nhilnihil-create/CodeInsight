#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
    int K, X; cin >> K >> X;
    if (K * 500 >= X) printf("%s\n", "Yes");
    else printf("%s\n", "No");
}
