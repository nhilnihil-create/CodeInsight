#include <algorithm>
#include <iostream>
#include <stack>
#include <queue>
#include <cmath>
#include <string>
#include <iterator>
#include <map>
#include <set>
#include <iomanip>
#include <vector>
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;
using Graph = vector<vector<int>>;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
#define INF 100000000000
#define MAX 200001
#define MOD 1000000007

int main(){
    int h1, m1, h2, m2, k;
    cin >> h1 >> m1 >> h2 >> m2 >> k;
    int time1 = h1 * 60 + m1;
    int time2 = h2 * 60 + m2;
    int ans = time2 - time1 - k;
    cout << ans << endl;
}   