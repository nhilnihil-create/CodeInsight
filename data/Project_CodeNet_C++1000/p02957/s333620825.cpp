#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <numeric>
#include <random>
#include <vector>
#include <array>
#include <bitset>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
 
using namespace std;
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;

int main() {
    ll a, b;
    cin >> a >> b;
    for(ll i = 0; i <= 1000000000; i++){
        if(abs(a-i) == abs(b-i)){
            cout << i;
            return 0;
        }
    }
    cout << "IMPOSSIBLE";
    return 0;
}