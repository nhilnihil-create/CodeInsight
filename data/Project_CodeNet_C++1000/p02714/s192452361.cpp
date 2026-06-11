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
    string s;
    cin >> n >> s;
    ll g = 0, ar[90]={0}, k, l;
    for (int i = 0; i < n; ++i) {
        ar[s[i]]++;
        for (int j = 0; j < n; ++j) {
            k = 2 * j + i;
            l = j + i;
            if (k >= n) break;
            if (s[i] != s[l] && s[i] != s[k] && s[l] != s[k])
                g++;
        }
    }

    cout << ar['R'] * ar['G'] * ar['B'] - g << endl;
}
