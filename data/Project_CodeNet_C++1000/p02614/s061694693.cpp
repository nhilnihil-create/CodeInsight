#include <iostream>
#include <algorithm>
#include <cmath>
#include <map>
#include <numeric>
#include <queue>
#include <string>
#include <vector>

int main(){
    int h, w, k;
    std::cin >> h >> w >> k;

    std::vector<std::vector<std::string>> c(h, std::vector<std::string>(w));
    for (int i = 0; i < h; i++)
    {
        std::string s;
        std::cin >> s;
        for (int j = 0; j < w; j++)
        {
            c[i][j] = s[j];
        }
    }
    
    int ans = 0;
    for (int i = 0; i < (1 << h); i++)
    {
        for (int j = 0; j < (1 << w); j++)
        {
            int black = 0;
            for (int ii = 0; ii < h; ii++)
            {
                for (int jj = 0; jj < w; jj++)
                {
                    if ((((i >> ii) & 1) == 0) && (((j >> jj) & 1) == 0) && (c[ii][jj] == "#"))
                    {
                        black++;
                    }
                }
            }
            
            if (black == k)
            {
                ans++;
            }
        }
    }
    
    std::cout << ans << std::endl;

    return 0;
}