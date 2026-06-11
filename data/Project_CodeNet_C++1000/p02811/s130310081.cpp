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

ll arr[200005];
ll nu_b[200005];

int main() {
    cio;
    int k, x;
    cin >> k >> x;
    if (500 * k >= x) cout << "Yes";
    else cout << "No";
    cn;
}
