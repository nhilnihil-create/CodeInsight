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
    int n;
    cin >> n;
    ll ar[n];
    for (int i = 0; i < n; ++i)
        cin >> ar[i];

    int a,b,c, x = 0;
    for (int i = 0; i < n; ++i)
        for (int j = i+1; j < n; ++j) {
            if (j == j+1) continue;
            for (int l = j+1; l < n; ++l) {
                if (l == j || l == i) continue;
                a = ar[i]; b = ar[j]; c = ar[l];
                if (a < b+c && b < c+a && c < a+b)
                    x++;
            }
        }

    cout << x;
    cn;
}
