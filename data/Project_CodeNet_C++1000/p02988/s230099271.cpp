#include <iostream>
#include <vector>

int main()
{
    int n; std::cin >> n;
    std::vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        std::cin >> v[i];
    }
    int cnt = 0;
    for (int i = 1; i < n-1; i++)
    {
        if (((v[i - 1] < v[i]) && (v[i] <= v[i + 1])) || ((v[i - 1] >= v[i]) && (v[i] > v[i + 1])))
        {
            cnt++;
        }
    }
    std::cout << cnt << std::endl;
    return 0;
}
