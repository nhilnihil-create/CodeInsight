
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

typedef pair<long double, long double> PLD;

PLD add(PLD p1, PLD p2) {
    PLD ret(p1.first + p2.first, p1.second + p2.second);
    return ret;
}

long double norm(PLD p) {
    return sqrt(p.first * p.first + p.second * p.second);
}

int main() {

    int N;
    cin >> N;

    vector<long double> x(N), y(N);
    for (int i = 0; i < N; i++) cin >> x[i] >> y[i];

    vector<PLD> xy(N);
    for (int i = 0; i < N; i++) xy[i] = make_pair(x[i], y[i]);

    sort(xy.begin(), xy.end(), [](const auto &p1, const auto &p2) {
        return atan2l(p1.second, p1.first) < atan2l(p2.second, p2.first);
    });

    long double ans = 0;

    for (int i = 0; i < N; i++) {
        PLD p(0, 0);
        for (int j = 0; j < N; j++) {
            p = add(p, xy[(i + j) % N]);
            ans = max(ans, norm(p));
        }
    }

    cout << fixed << setprecision(20) << ans << endl;

//    cout << atan2l(1, 1) << endl;
//    cout << atan2l(1, -1) << endl;
//    cout << atan2l(-1, 1) << endl;
//    cout << atan2l(-1, -1) << endl;
//
//    SHOW_MAP(xy);


}




























































