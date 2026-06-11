#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef long long int lli;

int main() {
    int N;
    cin >> N;
    int min = (int)(N / 1.09);
    int max = (int)(1 + (N / 1.07));
    for (int i = min; i <= max; i++) {
        int val = i * 1.08;
        if (val == N) {
            cout << i << endl;
            break;
        }
        if (i == max) {
            cout << ":(" << endl;
        }
    }
    return 0;
}
