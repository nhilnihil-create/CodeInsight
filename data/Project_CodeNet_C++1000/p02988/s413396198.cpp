#include<iostream>
#include<vector>

bool cond(int a, int b, int c) {
    if(b > a && b < c || b < a && b > c) {
        return true;
    } else {
        return false;
    }
}
int main () {

    int n;
    std::cin >> n;

    std::vector<int> p(n);
    for (int i = 0; i < n; i++)
    {
        std::cin >> p[i];
    }

    int ans = 0;
    for (int i = 1; i < n - 1; i++)
    {
        if(cond(p[i-1], p[i], p[i+1])) {
            ans++;
        }
    }

    std::cout << ans << std::endl;
}