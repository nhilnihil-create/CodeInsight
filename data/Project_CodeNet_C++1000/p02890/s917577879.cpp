#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>

struct Closed_Section {
    bool valid;
    int64_t begin;
    int64_t end;
    Closed_Section(bool _valid, int64_t _begin, int64_t _end) {
        valid = _valid; begin = _begin; end = _end;
    }
    Closed_Section() {
        valid = false, begin = 0; end = -1; //配列を定義するためにデフォルトコンストラクタが必要。
    }
    int64_t size() { return valid ? end - begin + 1 : 0; }
    void dump() { std::cout << "valid:" << valid << " begin:" << begin << " end:" << end << std::endl; }
};

Closed_Section binary_search(const int64_t L, const int64_t R, std::function<bool(int64_t)> func) {
    if (R < L) { return Closed_Section(false, L, R); }
    const bool res_L = func(L);
    const bool res_R = func(R);
    if (res_L && res_R) {
        return Closed_Section(true, L, R);
    } else if (!res_L && !res_R) {
        return Closed_Section(false, 0, -1);
    } else {
        int64_t lb = L;
        int64_t ub = R;
        while (lb + 1 < ub) {
            int64_t mid = (lb + ub) / 2;
            if (res_L == func(mid)) {
                lb = mid;
            } else {
                ub = mid;
            }
        }
        return res_L ? Closed_Section(true, L, lb) : Closed_Section(true, ub, R);
    }
}

Closed_Section binary_search(const Closed_Section& cs, std::function<bool(int64_t)> func) {
    return cs.valid ? binary_search(cs.begin, cs.end, func) : cs;
}

// end of template

int64_t N;
const int64_t MAX_N = 3e5 + 10;

int64_t A[MAX_N];
int64_t cnt[MAX_N] = {};
std::vector<int64_t> V, Vac;

bool check(int64_t K, int64_t X) {
    auto cs = binary_search(0, V.size()-1, [&](int64_t i){
        return V[i] < X;
    });
    int64_t num = 0;
    if (cs.valid) {
        num = Vac[cs.end] + X * (V.size() - cs.size());
    } else {
        num = X * V.size();
    }
    return K*X <= num;
}

int main(int argc, char **argv) {
    std::cin >> N;
    for (int64_t i = 1; i <= N; i++) {
        std::cin >> A[i];
        cnt[A[i]]++;
    }
    for (int64_t i = 1; i <= N; i++) {
        if (0 < cnt[i]) {
            V.push_back(cnt[i]);
        }
    }
    std::sort(V.begin(), V.end());
    for (int64_t i = 0; i < V.size(); i++) {
        Vac.push_back(V[i]);
        if (i != 0) {
            Vac[i] += Vac[i-1];
        }
    }
    for (int64_t k = 1; k <= N; k++) {
        auto cs = binary_search(0, N/k, [&](int64_t x){
            return check(k, x);
        });
        std::cout << cs.end << std::endl;
    }
}