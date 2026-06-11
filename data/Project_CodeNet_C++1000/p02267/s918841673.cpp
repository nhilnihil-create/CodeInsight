#include <iostream>
#include <vector>

int main(int argc, char const *argv[])
{
    int n;
    std::cin >> n;
    std::vector<int> s(n);
    for (int i = 0; i < n; i++) {
        std::cin >> s[i];
    }

    int q;
    std::cin >> q;
    std::vector<int> t(q);
    for (int i = 0; i < q; i++) {
        std::cin >> t[i];
    }

    int cnt = 0;
    for (int i = 0; i < q; i++) {
        for (int j = 0; j < n; j++) {
            if (s[j] == t[i]) {
                cnt++;
                break;
            }
        }
    }

    std::cout << cnt << std::endl;

    return 0;
}