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

vector<string> all;
string s;
void rec(int n, int prev){
    if(s.size() == n){
        all.push_back(s);
        return;
    }
    for(int i = max(0, prev - 1); i <= min(prev + 1, 9); ++i){
        s += (i + '0');
        rec(n, i);
        s.pop_back();
    }
}

void solve(){
    for(int i = 1; i <= 9; ++i){
        all.push_back(to_string(i));
    }
    int numDigs = 2;
    const int N = 1e5;
    while(all.size() < N){
        for(int i = 1; i <= 9; ++i){
            s = (i + '0');
            rec(numDigs, i);
        }
        numDigs++;
    }
    int k;
    cin >> k;
    cout << all[k - 1] << endl;
}

int main(int argv, char **argc){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t;
    t = 1;
    while(t--)
        solve();

}
