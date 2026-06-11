
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
#include <functional>
using namespace std;
typedef long long ll;


int main() {

    int n;
    cin >> n;
    int ans = 0;
    for (int i = 1; i < n;i++)
        ans += (n - 1) / i;

    cout << ans;

    return 0;
}