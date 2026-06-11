#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
using namespace std;
#define fio ios_base::sync_with_stdio(false); cin.tie(NULL);
#define M 1000000007
//#define FILE_A_IN

void solve() {
    int n;
    cin >> n;
    unordered_set<string> us;
    for (int i = 0; i < n; ++i) {
        char c[15]={0};
        cin >> c;
        string s = c;
        us.insert(s);
    }
    cout << us.size() << endl;
}
int main() {
#ifdef FILE_A_IN
    freopen("a.in", "r", stdin);
#endif
    fio;
        solve();
    return 0;
}