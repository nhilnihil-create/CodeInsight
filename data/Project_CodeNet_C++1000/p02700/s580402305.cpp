#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <utility>
#include <algorithm>
#include <cmath>
#include <climits>
#include <iomanip>
#include <queue>
#include <stack>

using namespace std;

typedef long long ll;

int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    
    int i = 0;
    while (1) {
        if (i%2 == 0) {
            c -= b;
            if (c <= 0) {
                cout << "Yes" << endl;
                return 0;
            }
        }
        else {
            a -= d;
            if (a <= 0) {
                cout << "No" << endl;
                return 0;
            }
        }
        i++;
    }
}