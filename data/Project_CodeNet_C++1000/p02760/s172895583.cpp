#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <fstream>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int mod = 1000000007;

int p[100005];

int root(int x) {return p[x] < 0 ? x : p[x] = root(p[x]);}

void mer(int x, int y) {
    if ((x = root(x)) == (y = root(y))) return;
    if (p[x] > p[y]) swap(x, y);
    p[x] += p[y];
    p[y] = x;
}

int main() {
    ios::sync_with_stdio(false);
    int a[3][3] = {}, n, b[3][3] = {}, c;
    for (int i = 0; i <3; i++) for (int j = 0; j <3; j++) cin >> a[i][j];
    cin >> n;
    while (n--) {
        cin >> c;
        for (int i = 0; i <3; i++) for (int j = 0; j <3; j++) if (c == a[i][j]) b[i][j] = 1;
    }
    if (b[0][0] && b[0][1] && b[0][2]) cout << "Yes";
    else if (b[1][0] && b[1][1] && b[1][2]) cout << "Yes";
    else if (b[2][0] && b[2][1] && b[2][2]) cout << "Yes";
    else if (b[0][0] && b[1][0] && b[2][0]) cout << "Yes";
    else if (b[0][1] && b[1][1] && b[2][1]) cout << "Yes";
    else if (b[0][2] && b[1][2] && b[2][2]) cout << "Yes";
    else if (b[0][0] && b[1][1] && b[2][2]) cout << "Yes";
    else if (b[2][0] && b[1][1] && b[0][2]) cout << "Yes";
    else cout << "No";
}
