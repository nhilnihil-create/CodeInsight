#include <algorithm>
#include <iostream>
#include <vector>
int main()
{
    int N, K, C;
    std::cin >> N >> K >> C;
    std::string s;
    std::cin >> s;
    std::vector<int> front(K);
    std::vector<int> back(K);
    int              farthest_front, farthest_back;
    int              count_front = -1, count_back = K;
    for (int i = 0; i < N; i++) {
        if (s[i] == 'o')
            if (count_front == -1 || (i - farthest_front) > C) {
                if (++count_front >= K) return 0;
                front[count_front] = i + 1;
                farthest_front     = i;
            }
        if (s[N - i - 1] == 'o')
            if (count_back == K || (i - farthest_back) > C) {
                if (--count_back < 0) return 0;
                back[count_back] = N - i;
                farthest_back    = i;
            }
    }
    for (int i = 0; i < K; i++)
        if (front[i] == back[i]) std::cout << front[i] << std::endl;
}