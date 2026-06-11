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
   int g = 0;
   if(s[0] == a[0]){
       g++;
   }
   if(s[2] == a[2]){
       g++;
   }
   if(s[1] == a[1]){
       g++;
   }
   cout << g;
    return 0;
}