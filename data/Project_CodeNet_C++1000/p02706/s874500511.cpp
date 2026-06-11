#include<iostream>
#include<vector>

int main() {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> a(m);
    long long sum = 0;
    for (int i = 0; i < m; i++)
    {
        std::cin >> a[i];
        sum += a[i];
    }

    int ans;
    if (n >= sum)
    {
        ans = n - sum;
    }
    else
    {
        ans = -1;
    }

    std::cout << ans << "\n";
}