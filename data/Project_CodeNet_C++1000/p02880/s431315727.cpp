#include <iostream>
#include <string.h>
#include <cstring>
#include <math.h>
#include <algorithm>
#include <functional>
#include <stack>
#include <queue>
#include <vector>
#include <map>

using namespace std;

#define cn cout << '\n'
#define cio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll long long
#define ii pair < int, int >
#define iii pair < int, ii >
#define INF 987654321
#define LINF 987654321987654321

int main() {
    cio;
    int n,i; cin >> n;
    bool b = false;
    for (i = 9; i > 0; --i)
    {
        if (n % i == 0 && n / i <= 9)
        { b = !b; break; }
    }

    if (!b)
        cout << "No\n";
    else
        cout << "Yes\n";
    cn;
    return 0;
}
