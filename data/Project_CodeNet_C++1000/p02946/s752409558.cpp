#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include<iomanip>
using namespace std;
typedef long long ll;

int main() {
    int k, x; cin >> k >> x;
    k--;
    for (int i = k * (-1); i <= k; i++) {
        cout << x + i << endl;
    }
}
