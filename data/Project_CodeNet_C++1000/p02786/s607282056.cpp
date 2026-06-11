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

ll bin() {

    return INF;
}

int main() {
    cio;
    ll H;
    cin >> H;
    ll l = 0;
    ll pw = 1;
    while (H >= 1) {
        H /= 2;
        l += pw;
        pw *= 2;
    }
    cout << l;
    cn;
}
