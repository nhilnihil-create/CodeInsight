#include <stdio.h>

#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>
using namespace std;
typedef long long ll;
const ll maxn = 1e5 + 111;
int main() {
    int a, b, c;
    cin >> a >> b >> c;
    if (b * c >= a)
        puts("Yes");
    else
        puts("No");
    return 0;
}