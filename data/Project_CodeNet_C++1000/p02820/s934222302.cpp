#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#include <map>
#include <iomanip>
#define intt long long
#define PI 3.14159265358979323846

using namespace std;
int main() {
    intt N, K, R, S, P; std::cin >> N >> K >> R >> S >> P;
    std::string T; std::cin >> T;
    intt ans = 0;
    for (int i = 0; i < K; ++i) {
        std::string s;
        int j = i;
        while (j < N) {
            s.push_back(T[j]);
            j += K;
        }
        int t = 0;
        for (int k = 0; k < s.size(); ++k) {
            if (k > 0 && s[k] == s[k - 1] && t == 1) {
                t = 0;
                continue;
            }
            else {
                if (s[k] == 'r')
                    ans += P;
                else if (s[k] == 's')
                    ans += R;
                else if (s[k] == 'p')
                    ans += S;
                t = 1;
            }
        }
    }
    std::cout << ans << std::endl;

    return 0;
}