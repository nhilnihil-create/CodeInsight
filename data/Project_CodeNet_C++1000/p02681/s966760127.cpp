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
    string s, t;
    cin >> s >> t;
    int g = s.length();
    int l = t.length();
    int b = 0;
    for(int i = 0; i < g; i++){
        if(s[i] == t[i] && (g + 1) == l){
            b++;
        }
    }
    if(b == g){
        cout << "Yes";
    } else{
        cout << "No";
    }
    return 0;
}