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
    ll n;
    cin >> n;
    if(n == 2){
        cout  << 1 << endl;
        return;
    }
    ll ans = 1;
    for(ll i = 2; i * i <= n - 1; ++i){
        if((n-1) % i == 0){
            ans += 2;
            if((n-1)/i == i)
                ans--;
        }
    }
    ans++;
    for(ll i = 2; i * i <= n; ++i){
        if(n % i == 0){
            ll copy = n;
            while(copy % i == 0){
                copy /= i;
            }
            ans += (copy % i == 1);
        }
    }
    cout << ans << endl;
}


int main(int argv, char **argc){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t;
    t = 1;
    while(t--)
        solve();

}
