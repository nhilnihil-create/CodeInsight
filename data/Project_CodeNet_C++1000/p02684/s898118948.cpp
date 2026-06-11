#include <iostream>
#include <vector>

template<class S, S (*next)(S), int (*idx)(S)>
struct doubling {
    doubling(int _n, long long _max_k) : n(_n) {
        log = 1;
        while (1LL << log < _max_k) log++;
        t = std::vector<std::vector<int>>(log, std::vector<int>(_n));
        for (int i = 0; i < _n; ++i) t[0][i] = next(i);
    }

    void init() {
        for (int k = 0; k < log - 1; k++) {
            for (int i = 0; i < n; i++) t[k + 1][i] = t[k][idx(t[k][i])];
        }
    }

    S query(S s, long long k) {
        S now = s;
        for (int _k = 0; k > 0; _k++) {
            if (k & 1) now = t[_k][idx(now)];
            k >>= 1;
        }
        return now;
    }

    private:
        int n, log;
        std::vector<std::vector<S>> t;
};


std::vector<int> A;
int next (int n) { return A[n]; }
int idx(int n) { return n; }

int main(){
    int N;
    long long K;
    std::cin >> N >> K;

    A = std::vector<int>(N);
    for (auto &i : A) std::cin >> i, i--;

    doubling<int, next, idx> d(N, K);
    d.init();
    std::cout << d.query(0, K) + 1 << std::endl;
}
