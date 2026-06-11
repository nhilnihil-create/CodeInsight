#include <iostream>
#include <vector>
#include <cmath>
#include <bitset>
#include <random>
#include <ctime>
using namespace std;
using ll = long long int;
using P = pair<int, int>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
ll mod = 1000000007;

int main() {
    int n;
    cin >> n;
    int ans = 0;
    ans = (n + 1000 - 1) / 1000;
    cout << (1000 * ans) - n << endl;
}
