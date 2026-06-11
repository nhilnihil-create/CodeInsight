#include <iostream>
#include <vector>

void comb(std::vector<std::vector<unsigned long long int>> &c)
{
    for (int i = 0; i < c.size(); i++)
    {
        c[i][0] = 1;
        c[i][i] = 1;
    }
    for (int i = 1; i < c.size(); i++)
    {
        for (int j = 1; j <= (i / 2 + 1); j++)
        {
            c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
            c[i][i - j] = c[i][j];
        }
    }
}

int main(){
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<unsigned long long int>> c(n + m + 1, std::vector<unsigned long long int>(n + m + 1));

    comb(c);

    std::cout << c[n + m][2] - n * m << std::endl;

    return 0;
}