#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include<iomanip>
using namespace std;
typedef long long ll;

int main() {
    int a, b, c; cin >> a >> b >> c;
    cout << (c - (a - b) >= 0 ? c - (a - b) : 0) << endl;
}
