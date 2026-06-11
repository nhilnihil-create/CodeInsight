#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()

int main(void){

    int x, y, z;
    cin >> x >> y >> z;

    swap(x, y);
    swap(x, z);

    printf("%d %d %d\n", x, y, z);

    return 0;
}