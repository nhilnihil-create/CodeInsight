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

int main() {
    ios::sync_with_stdio(false);
    //2 3 3 1 3 1
    //3 5 6 5 8 7
    //-1 -1 0 3 2 5
    //a[i]+a[j]=j-i
    //a[i]+i=j-a[j]
    int n, a[200005] = {};
    ll z = 0;
    map<int, int> m;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) {
        z += m[i - a[i]];
        m[i + a[i]]++;
    }
    cout << z;
}
