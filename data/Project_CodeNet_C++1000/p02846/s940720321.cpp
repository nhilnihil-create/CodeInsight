#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#define MOD 1000000007
using namespace std;

typedef pair<int, int> P;
typedef pair<long long, long long> LLP;

int main() {
    long long T[2], A[2], B[2];
    cin >> T[0] >> T[1] >> A[0] >> A[1] >> B[0] >> B[1];
    
    long long D[2];
    for (int i = 0; i < 2; i++) D[i] = T[i] * (A[i] - B[i]);
    if (D[0] + D[1] == 0) {
        cout << "infinity" << endl;
        return 0;
    } else {
        if (D[0] > 0) {
            D[0] *= -1;
            D[1] *= -1;
        }
        if (D[0] + D[1] < 0) {
            cout << 0 << endl;
        } else {
            long long S = (-1) * D[0] / (D[0] + D[1]);
            long long T = (-1) * D[0] % (D[0] + D[1]);
            cout << (2 * S + (T == 0 ? 0 : 1)) << endl;
        }
    }
    return 0;
}