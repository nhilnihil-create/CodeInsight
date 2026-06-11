#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <set>
#include <cmath>
#include <iomanip>
#include <tuple>
#include <map>
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;
const int INF = 1000000000;

typedef pair<int,int> P;

int main() {
    int n,x,y; cin >> n >> x >> y;
    vector<int> dis(n,0);
    for (int i = 1; i < n; i++) {
        for (int j = i + 1; j < n + 1; j++) {
            int tmp = min(j - i, min(abs(x - i) + abs(y - j) + 1, abs(x - j) + abs(y - i) + 1));
            dis[tmp]++;
        }
    }
    for (int k = 1; k < n; k++) cout << dis[k] << "\n";
}