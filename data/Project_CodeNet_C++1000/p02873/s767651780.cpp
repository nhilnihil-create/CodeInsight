#include <iostream>
#include <vector>

int main()
{
    std::string S;
    std::cin >> S;
    std::vector<int64_t> sign;

    char prev = S[0];
    int64_t continuous = 0;
    for (int64_t i = 0; i < S.size(); ++i)
    {
        if (S[i] == '<')
        {
            if (prev != S[i])
            {
                sign.emplace_back(continuous);
                prev = S[i];
                continuous = 0;
            }
            ++continuous;
        }
        else
        {
            if (prev != S[i])
            {
                sign.emplace_back(continuous);
                prev = S[i];
                continuous = 0;
            }
            --continuous;
        }
    }
    sign.emplace_back(continuous);

    int64_t num = 0, sum = 0;
    for (int64_t i = 0; i < sign.size(); ++i)
    {
        int64_t tmp = sign[i];
        if (tmp > 0)
        {
            sum += tmp * (tmp - 1) / 2;
            num = tmp;
        }
        else
        {
            tmp = -tmp;
            sum += tmp * (tmp - 1) / 2;
            if (num < tmp)
                num = tmp;
            sum += num;
        }
    }
    if (sign.at(sign.size() - 1) > 0)
        sum += num;

    std::cout << sum;
}