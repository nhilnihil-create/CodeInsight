#include <vector>
#include <string>
#include <iostream>
#include <iomanip>
#include <queue>
#include <algorithm>
#include <functional>
#include <map>
#include <array>
#include <cmath>
#include <set>
#include <numeric>

using namespace std;

template <typename T>
using TABLE = vector<vector<T>>;

using LONG = long long;
using LVEC = vector<long long>;

#define FOR(_i, s, e) for(_i = s; _i < e; ++_i)
#define FOR_INV(_i, s, e) for(_i = e - 1; _i >= s; --_i)

long long PRIME = 1e9 + 7;
long long PRIME2 = 998244353;


using pos = std::pair<LONG, LONG>;


int main(){
    LONG N, M;
    cin >> N >> M;

    vector<pos> BA(N);
    LONG i;
    LONG A, B;

    FOR(i, 0, N){
        cin >> A >> B;
        BA[i].first = B;
        BA[i].second = A;
    }

    sort(BA.begin(), BA.end(), greater<pos>());


    std::set<LONG> days;
    FOR(i, 0, M){
        days.insert(i + 1);
    }

    LONG sum = 0;

    for(pos& d : BA){
        auto it = days.lower_bound(d.second);
        if(it == days.end()){
            continue;
        }

        sum += d.first;
        days.erase(it);
    }

    cout << sum << endl;

}

