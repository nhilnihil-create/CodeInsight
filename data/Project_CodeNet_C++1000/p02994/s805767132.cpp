#include<iostream>
#include<string>
#include<algorithm>
#include<vector>


int main () {
    int n, l;
    std::cin >> n >> l;

    std::vector<int> ts(n);
    std::vector<int> tsa(n);

    for (int i = 0; i < n; i++) {
        ts[i] = i + l;
        tsa[i] = std::abs(i + l);
    }

    int mina = *std::min_element(tsa.begin(), tsa.end());

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if(mina != tsa[i]) {
            ans += ts[i];
        }
    }

        std::cout << ans << std::endl;
}