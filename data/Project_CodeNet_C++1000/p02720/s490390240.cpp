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
    queue<long long> q;
    for(int i = 1; i <= 9; ++i){
        q.push(i);
    }
    int k;
    cin >> k;
    ll x;
    while(k--){
        x = q.front();
        q.pop();
        if(x % 10 != 0){
            q.push(10 * x + (x % 10) - 1);
        }
        q.push(10 * x + (x % 10));
        if(x % 10 != 9){
            q.push(10 * x + (x % 10) + 1);
        }
    }
    cout << x << endl;

}
int main(int argv, char **argc){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t;
    t = 1;
    while(t--)
        solve();
}

