#include <iostream>
#include <vector>
#include <map>
#include <string>

int main() {
	int N; std::cin >> N;
    int ans = 0;
	std::string S; std::cin >> S;
    for (int i = 0; i < 1000; i++) {
        int a[3] = { i / 100, (i / 10) % 10, i % 10 };
        int cnt = 0;
        for (int j = 0; j < N; j++) {
            if (cnt <= 2 && a[cnt] == (int)(S[j] - '0')) cnt++;
        }
        if (cnt == 3) ans += 1;
    }
    std::cout << ans << std::endl;
        return 0;
}