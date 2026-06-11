#include <iostream>
#include <array>
#include <algorithm>
#include <numeric>

using namespace std;

#define all(c) (c).begin(), (c).end()

template<class ForwardIt>
pair<ForwardIt, ForwardIt> sieve(ForwardIt begin, ForwardIt end){
    return make_pair(begin, (*begin) * (*begin) <= *(end - 1) ?
            sieve(begin + 1, remove_if(begin + 1, end, [=](int x){return x % *begin == 0;})).second : end);
}

int main(){
    constexpr size_t N = 123456 * 2;
    array<int, N> p; iota(all(p), 2);
    auto itr = sieve(all(p));
    int n;
    while(cin >> n, n)cout << upper_bound(itr.first, itr.second, n+n) - upper_bound(itr.first, itr.second, n) << '\n';
    return 0;
}