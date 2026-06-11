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
using ll = long long;
#define endl '\n'
#define debug(name) DEBUG(#name, (name))
template<typename T>
void DEBUG(string label, T value) {
    cerr << "[" << label << " = " << value << "]\n";
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n, m; ll k;
    cin >> n >> m >> k;
    ll s1=0, s2=0;
    vector<int> one(n), two(m);
    for(int i = 0; i < n; ++i){
        cin >> one[i];
    }
    for(int i = 0; i < m; ++i){
        cin >> two[i];
        s2 += two[i];
    }
    int p = m - 1;
    int ans = 0;
    if(s2 <= k){
        ans = m;
    }
    for(int i = 0; i < n; ++i){
        s1 += one[i];
        while(p >= 0 && s2 > k - s1){
            s2 -= two[p];
            p--;
        }
        if(s1 + s2 <= k)
            ans = max(ans, i + 1 + p + 1);
    }
    if(s1 <= k){
        ans = max(ans, n);
    }
    s2 = 0;
    p = n - 1;
    for(int i = 0; i < m; ++i){
        s2 += two[i];
        while(p >= 0 && s1 + s2 > k){
            s1 -= one[p];
            p--;
        }
        if(s1 + s2 <= k)
            ans = max(ans, i + 1 + p + 1);
    }
    cout << ans << endl;
}
