#include <iostream>
#include <map>
#include <vector>

int main()
{
    int n, k, c;
    std::cin >> n >> k >> c;
    std::string str;
    std::cin >> str;

    std::vector<int> l, r;
    std::map<int, int> map_l, map_r;
    int count_l = 0;
    int count_r = 0;
    int rest_l  = c + 1;
    int rest_r  = c + 1;

    for (int i = 0; i < n; ++i)
    {
        int j = (n - 1) - i;
        if (str[i] == 'o' && rest_l >= c)
        {
            ++count_l;
            map_l.insert(std::make_pair(count_l, i));
            rest_l = 0;
        }
        else
        {
            ++rest_l;
        }
        l.push_back(count_l);

        if (str[j] == 'o' && rest_r >= c)
        {
            ++count_r;
            map_r.insert(std::make_pair(count_r, j));
            rest_r = 0;
        }
        else
        {
            ++rest_r;
        }
        r.push_back(count_r);
    }

    for (int i = 0; i < n; ++i)
    {
        int j = (n - 1) - i;

        if (str[i] == 'o')
        {
            int count = l[i] + r[j] - 1;
            if (count == k)
            {
                if (map_l.at(l[i]) == i && map_r.at(r[j]) == i)
                {
                    std::cout << i + 1 << std::endl;
                }
            }
        }
    }

    return 0;
}
