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
    int a, b, c;
    cin >> a >> b >> c;
    int k;
    cin >> k;   
    int g = 0;
    for(int i = 0; i < k; i++){
        if(a > 0){
            g++;
            a--;
        }else if(b > 0){
            b--;
        }else{
            c--;
            g--;
        }
    }
    cout << g;
    return 0;
}