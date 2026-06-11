#include <cstdio>
#include <vector>

int main()
{
    int n, m, x; scanf("%d %d %d", &n, &m, &x);
    std::vector<std::vector<int>> book(n, std::vector<int>(m+1));
    std::vector<int> count_cost(m+1, 0);
    int min_cost = 13 * 100000;

    for (int i=0; i<n; i++)
    {
        for (int j=0; j<m+1; j++)
        {
            scanf("%d", &book.at(i).at(j));
        }
    }

    for (int i=1; i < (1 << n); i++)
    {
        int bit = i;
        int current = 0;
        for (int j=0; j<m+1; j++) count_cost.at(j) = 0;
        while (1)
        {
            if (bit % 2 == 1)
            {
                for (int j=0; j<m+1; j++) count_cost.at(j) += book.at(current).at(j);
            }
            current++;
            bit /= 2;

            bool all_true = true;
            for (int j=1; j<m+1; j++)
            {
                if (count_cost.at(j) < x) all_true = false;
            }
            if (all_true && count_cost.at(0) < min_cost) {min_cost = count_cost.at(0); break;}

            if (bit == 0) break;
        }

    }

    if (min_cost == 13 * 100000) printf("-1\n");
    else printf("%d\n", min_cost);

    return 0;
}

