#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<(int)(n); i++)
using ll = long long;

int main() {
    int x,y,z;
    cin >> x >> y >> z;

    swap(x,y);
    swap(x,z);

    printf("%d %d %d\n", x, y, z);
    return 0;
}