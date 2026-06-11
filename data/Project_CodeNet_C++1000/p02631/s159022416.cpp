#include <memory.h>

#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <utility>
#include <vector>

using namespace std;

#define MOD 998244353
#define INIT -1

int main()
{
    int n;
    cin >> n;
    int xorsum = 0;
    int a[200000];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        xorsum = xorsum ^ a[i];
    }
    for (int i = 0; i < n; i++) {
        int ans = xorsum ^ a[i];
        cout << ans << " ";
    }
    cout << endl;

}