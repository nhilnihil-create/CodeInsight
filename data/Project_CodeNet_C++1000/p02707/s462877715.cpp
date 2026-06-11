#include <iostream>
#include <vector>

int main()
{
    int N;
    std::cin >> N;
    std::vector<int> ns;
    ns.resize(N + 1);
    for (int i = 2; i <= N; i++)
    {
        int A;
        std::cin >> A;
        ns[A]++;
    }
    for (int i = 1; i <= N; i++)
    {
        std::cout << ns[i] << std::endl;
    }
}