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
    int n, a = 0;
    string s;
    cin >> n >> s;
    for (int i = 0; i < s.size() - 2; ++i) {
        if (s[i] == 'A' &&
          s[i+1] == 'B' &&
          s[i+2] == 'C') {
            a++;
        }
    }
    cout << a;
    cn;
}
