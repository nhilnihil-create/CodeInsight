#include <iostream>
#include <vector>
#include <deque>

///////////////////////////////////////////////////

int main()
{
    int N, M;
    std::string S;
    std::cin >> N >> M >> S;
    
    std::vector<bool> grid(N+1);
    for (int i = 0; i <= N; ++i)
        grid[i] = (S[i] == '1');
    
    std::deque<int> list;
    bool can_pass = true;
    int i = 0;
    while (i < N && can_pass)
    {
        can_pass = false;
        for (int m = M; m >= 1 && !can_pass; --m)
        {
            if (i + m <= N && !grid[N - i - m])
            {
                i += m;
                list.push_front(m);
                can_pass = true;
            }
        }
    }
    
    if (can_pass)
    {
        for (int d : list)
            std::cout << d << " ";
        std::cout << std::endl;
    }
    else
    {
        std::cout << -1 << std::endl;
    }
}