#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;
#define ll long long
#define N 1000000007

int c[10][10];

int main()
{
    int n;
    cin >> n;
    for (int k = 0; k <= 6; k++) {
        int b = pow(10, k);
        for (int i = b; i < min(n + 1, 10 * b); i++) {
            c[i / b][i % 10]++;
        }
    }
   ll cnt = 0;
    for (int i = 1; i < 10; i++) {
        for (int j = 1; j < 10; j++) {
            cnt += c[i][j] * c[j][i];
        }
    }
   cout << cnt << endl;
    return 0;
}