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
    int n, m;
    cin >> n >> m;
    int s = 0;
    int a[n];
    for(int i = 0; i < n; ++i){
        cin >> a[i];
        s += a[i];
    }
    int ans = 0;
    for(int i = 0; i < n; ++i){
        if(a[i] >= (s+4*m-1)/(4*m))++ans;
    }
    if(ans >= m){
        cout << "Yes\n";
    }
    else
        cout << "No" << endl;
}
int main(int argv, char **argc){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t;
    t  = 1;
    while(t--)
        solve();

}
