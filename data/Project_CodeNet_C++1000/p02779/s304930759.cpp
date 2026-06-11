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
    int N; cin >> N;
    int ar[N];
    map<int, int> m;
    string ans = "YES";
    for (int i =0; i < N; ++i) {
        cin >> ar[i];
        m[ar[i]]++;
        if (m[ar[i]] > 1) {
            ans = "NO";
            break;
        }
    }

    cout << ans << endl;
}
