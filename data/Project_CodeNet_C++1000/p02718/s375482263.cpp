#include<iostream>
#include<string>
#include<vector>

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<int> a(n);
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        std::cin >> a[i];
        sum += a[i];
    }

    bool f = false;
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if(1.0*sum /(4.0*m) <= a[i]) {
            cnt++;
        }

        if(cnt == m) {
            f = true;
            break;
        }
    }

    

    std::string ans = f ? "Yes" : "No";
    std::cout << ans << "\n";
}