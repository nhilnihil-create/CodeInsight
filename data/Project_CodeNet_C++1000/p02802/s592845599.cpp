#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using ll = long long;
using lli = long long int;

lli n, m, p;
std::string s;

int main() {
    std::cin >> n >> m;
    std::vector<ll> vec;
    std::vector<ll> wa;
    vec.assign(n+1, 0);
    wa.assign(n+1, 0);
    for (int i = 0; i < m; i++) {
        std::cin >> p >> s;
        if (s == "AC") {
            vec[p] = 1;
        }
        else if (s == "WA" && vec[p] == 0) {
            wa[p]++;
        }
    }
    ll sum_wa = 0;
    for (int i = 1; i < wa.size(); i++) {
        if (vec[i] == 1) {
            sum_wa += wa[i];
        }
    }
    ll num_ac = std::count(vec.begin()+1, vec.end(), 1);
    std::cout << num_ac << " " << sum_wa << std::endl;

}
