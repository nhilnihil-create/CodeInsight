
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

    int N;
    cin >> N;

    string S;
    cin >> S;

    for (int i = 0; i < 2 * N; i += 2) {
        if (S[i] == 'B') S[i] = 'W';
        else S[i] = 'B';
    }

    LL ans = 1;
    LL W = 0;
    LL B = 0;

    for (int i = 0; i < 2 * N; i++) {
        if (S[i] == 'B') {
            if(W == 0){
                cout << 0 << endl;
                return 0;
            }
            ans *= W;
            W--;
            ans %= mod;
        } else {
            W++;
        }
    }

    if(W > 0){
        cout << 0 << endl;
        return 0;
    }

    for (LL i = 1; i <= N; i++) {
        ans *= i;
        ans %= mod;
    }

    cout << ans << endl;

}




























































