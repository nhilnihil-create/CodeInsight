#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

std::vector<int> z_algorithm(const std::string& S) {
    const int N = S.size();
    std::vector<int> res(N);

    res[0] = N;
    int i = 1, j = 0;
    while (i < N) {
        while (i + j < N && S[j] == S[i + j]) ++j;
        res[i] = j;

        if (j == 0) {
            ++i;
            continue;
        }

        int k = 1;
        while (i + k < N && k + res[k] < j) {
            res[i + k] = res[k];
            ++k;
        }
        
        i += k;
        j -= k;
    }

    return res;
}

int main() {
    int N;
    std::string S;
    std::cin >> N >> S;

    int ans = 0;
    for (int i = 0; i < N; i++) {
        std::string T = S.substr(i);
        auto v = z_algorithm(T);

        for (int j = 0; j < v.size(); j++) {
            ans = std::max(ans, std::min(j, v[j]));
        }
    }
    std::cout << ans << "\n";
}