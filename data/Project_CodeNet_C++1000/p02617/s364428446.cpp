#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
#include <vector>
#include <deque>
#include <list>
#include <queue>
#include <math.h>
#include <assert.h>
#include <set>
#include <map>
#include <bitset>
#include <ctime>
#include <time.h>
#include <algorithm>
#include <cstdio>
#include <fstream>
#include <stack>
#include <ctype.h>
#include <numeric>
#include <sstream>
#include <unistd.h>
#include <unordered_map>
#include <unordered_set>
#include <limits>
#include <random>
#include <chrono>
#include <iomanip>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef long long ll;
#define endl '\n'
#define debug(name) DEBUG(#name, (name))
template<typename T>
void DEBUG(string label, T value) {
    cerr << "[" << label << " = " << value << "]\n";
}

void solve(){
    int V;
    cin >> V;
    ll edges = 0;
    for(int i = 0; i < V - 1; ++i){
        int a, b;
        cin >> a >> b;
        edges += 1LL * min(a, b) * (V - max(a, b) + 1);
    }
    cout << 1LL * V * (V + 1) * (V + 2) / 6 - edges << endl;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t;
    t = 1;
    while(t--){
        solve();
    }
}
