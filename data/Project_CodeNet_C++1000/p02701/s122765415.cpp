#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <iomanip>
#include <map>
#include <cmath>
#include <bitset>
using namespace std;

typedef long long ll;
typedef pair<int,int> Pi;
const ll inf = 1e18 + 1;
const ll limit = 1e9;

int main() {
    int n; cin >> n;
    map<string,int> mp;
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        mp[s]++;
    }
    cout << mp.size() << "\n";
}   
 