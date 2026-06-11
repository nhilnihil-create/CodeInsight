	
 //include
 //------------------------------------------
 #include <vector>
 #include <list>
 #include <map>
 #include <unordered_map>
 #include <climits>
 #include <set>
 #include <unordered_set>
 #include <deque>
 #include <stack>
 #include <bitset>
 #include <algorithm>
 #include <functional>
 #include <numeric>
 #include <utility>
 #include <sstream>
 #include <iostream>
 #include <iomanip>
 #include <cstdio>
 #include <cmath>
 #include <cstdlib>
 #include <cctype>
 #include <string>
 #include <cstring>
 #include <ctime>
 #include <queue>
 #include <random>
 #include <complex>
 #include <regex>
 #include <locale>
 #include <random>
 #include <type_traits>
 
 using namespace std;
 
 #define SHOW_VECTOR(v) {std::cerr << #v << "\t:";for(const auto& xxx : v){std::cerr << xxx << " ";}std::cerr << "\n";}
 #define SHOW_MAP(v){std::cerr << #v << endl; for(const auto& xxx: v){std::cerr << xxx.first << " " << xxx.second << "\n";}}
 
 using LL = long long;
 
 //------------------------------------------
 //------------------------------------------
 
 constexpr LL mod = 1e9 + 7;
 
 int main() {
 
     string S;
     cin >> S;
 
     int N = 13;
 
     string T = S;
     reverse(T.begin(), T.end());
 
     vector<LL> dp(N, 0);
     dp[0] = 1;
 
     LL base = 1;
     for (int i = 0; i < T.size(); i++) {
         vector<LL> next(N, 0);
         if (T[i] == '?') {
             for (int k = 0; k <= 9; k++) {
                 LL d = (k * base);
                 for (int j = 0; j < N; j++) {
                     next[(d + j) % N] += dp[j];
                     next[(d + j) % N] %= mod;
                 }
             }
         } else {
             for (int j = 0; j < N; j++) {
                 LL d = ((T[i] - '0') * base);
                 next[(d + j) % N] += dp[j];
                 next[(d + j) % N] %= mod;
             }
         }
         dp = next;
         base *= 10;
         base %= 13;
     }
 
     cout << dp[5] << endl;
 
 }
 