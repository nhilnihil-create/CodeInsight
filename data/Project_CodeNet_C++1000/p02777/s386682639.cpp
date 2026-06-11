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
    string s, a;
    cin >> s >> a;
    int n, g;
    cin >> n >> g;
    string h;
    cin >> h;
    if(s == h){
        n--;
    }else{
        g--;
    }
    cout << n << " " << g;
    
    return 0;
}