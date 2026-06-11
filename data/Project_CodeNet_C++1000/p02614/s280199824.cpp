#include <iostream>

char map[6][6] = {};
int main()
{
    int H, W, K;
    std::cin >> H >> W >> K;
    int n_black = 0;
    for (int j = 0; j < H; j++)
    {
        for (int i = 0; i < W; i++)
        {
            std::cin >> map[j][i];
            if (map[j][i] == '#')
                n_black++;
        }
    }
    int count = 0;
    // 2^H * 2^W <= 2^6 * 2^6 = 2^12 = 4096
    for (int row = 0; row < (1 << H); row++)
    {
        for (int column = 0; column < (1 << W); column++)
        {
            int n = 0; // 残る黒石の数
            for (int i = 0; i < H; i++)
            {
                if (row & (1 << i))
                    continue;
                for (int j = 0; j < W; j++)
                {
                    if (column & (1 << j))
                        continue;
                    if (map[i][j] == '#')
                        n++;
                }
            }
            if (n == K)
                count++;
        }
    }
    std::cout << count << std::endl;
}