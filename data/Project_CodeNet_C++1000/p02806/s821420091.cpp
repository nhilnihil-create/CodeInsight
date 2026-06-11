#include <iostream>
#include <algorithm>
#include <numeric>
#include <string>
#include <vector>

int main()
{
    int N;
    std::vector<std::string> titles;
    std::vector<int> lengths;
    std::string X;

    std::cin >> N;

    titles.resize(N);
    lengths.resize(N);

    for (auto i = 0; i < N; i++)
    {
        titles[i].reserve(101);
        std::cin >> titles[i] >> lengths[i];
    }
    X.reserve(101);
    std::cin >> X;

    std::vector<int> indices;
    indices.resize(N);
    std::iota(indices.begin(), indices.end(), 0);

    for (auto char_idx = 0; indices.size() > 1; char_idx++)
    {
        indices.erase(
            std::remove_if(indices.begin(), indices.end(),
                           [&](int idx) {
                               return titles[idx][char_idx] != X[char_idx];
                           }),
            indices.end());
    }
    std::cout << std::accumulate(lengths.begin() + indices.front() + 1, lengths.end(), 0) << std::endl;

    return 0;
}