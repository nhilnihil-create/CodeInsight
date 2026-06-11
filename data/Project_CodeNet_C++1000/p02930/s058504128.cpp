#include <bits/stdc++.h>

int main() {
    using namespace std;
    constexpr unsigned long MOD = 1000000007;
    unsigned long N;
    cin >> N;
    vector<vector<unsigned long>> edge(N);
    for(unsigned long i = 0; i < N; ++i)edge[i].resize(N - i - 1);
    [&N, rec = [&edge](auto f, auto l, auto r, auto lower) -> void{
        if(l + 1 >= r)return;
        auto mid = (l + r) / 2;
        for(unsigned long i = l; i < mid; ++i)for(unsigned long j = mid; j < r; ++j)edge[i][j - i - 1] = lower;
        f(f, l, mid, lower + 1);
        f(f, mid, r, lower + 1);
    }]{rec(rec, 0, N, 1);}();
    for(const auto& i : edge){
        for(const auto& j : i)cout << j << " ";
        cout << endl;
    }
    return 0;
}