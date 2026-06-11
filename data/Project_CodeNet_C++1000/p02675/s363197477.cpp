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
    int n;
    cin >> n;
    switch(n % 10){
        case 2:
        case 4:
        case 5:
        case 7:
        case 9: cout << "hon"; break;
        case 0:
        case 1:
        case 6:
        case 8: cout << "pon"; break;
        case 3: cout << "bon";
    }
    
    
    
    return 0;
}