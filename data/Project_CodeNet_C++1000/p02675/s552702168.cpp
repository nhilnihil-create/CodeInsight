#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int mod = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    int n;
    cin >> n; n %= 10;
    if (n == 2 || n == 4 || n == 5 || n == 7 || n == 9) cout << "hon";
    else if (n == 3) cout << "bon";
    else cout << "pon";
}
