#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_dec_float.hpp>

int main(){
    using namespace std;
    unsigned long N;
    cin >> N;
    vector<pair<long, long>> eng(N);
    for(auto& i : eng)cin >> i.first >> i.second;
    auto d = static_cast<unsigned long>(partition(eng.begin(), eng.end(), [](auto i){return i.first == 0 ? i.second > 0 : i.first > 0;}) - eng.begin());
    for(unsigned long i = 0; i < N; ++i)eng.emplace_back(-eng[i].first, -eng[i].second);
    for(unsigned long i = 0; i < d; ++i)eng.emplace_back(eng[i].first, eng[i].second);
    auto cmp = [](auto i, auto j){return i.first * j.second > i.second * j.first;};
    sort(eng.begin(), eng.begin() + d, cmp);
    sort(eng.begin() + d, eng.begin() + d + N, cmp);
    sort(eng.begin() + d + N, eng.end(), cmp);
    long a{0}, b{0};
    unsigned long ans{0};
    for(unsigned long i = 0; i < 2 * N + d; ++i){
        a += eng[i].first;
        b += eng[i].second;
        ans = max<unsigned long>(ans, a * a + b * b);
    }
    boost::multiprecision::cpp_dec_float_50 t(ans), k(boost::multiprecision::sqrt(t));
    cout << k.str() << endl;
    return 0;
}