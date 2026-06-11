#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007

int main() {
    int H, A;
    cin >> H >> A;

    cout << H / A + (H % A != 0) << endl;
}
