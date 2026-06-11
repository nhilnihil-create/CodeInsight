#include <iostream>
#include <vector>
using namespace std;

#define MAX_COST 200

int main()
{
    int h,w;
    cin >> h >> w;
    vector<vector<char>> mat(h,vector<char>(w));
    vector<vector<int>> ans(h,vector<int>(w));
    for(int i = 0; i < h; ++i)
    {
        for(int j = 0; j < w; ++j)
        {
            cin >> mat[i][j];
        }
    }

    for(int i = 0; i < h; ++i)
    {
        for(int j = 0; j < w; ++j)
        {
            int u = MAX_COST;
            int l = MAX_COST;

            if(i == 0 && j == 0)
            {
                if(mat[i][j] == '#')
                {
                    ans[i][j] += 1;
                }
                continue;
            }
            if(i != 0)
            {
                u = ans[i-1][j];
                if(mat[i-1][j] == '.'
                && mat[i][j] == '#')
                {
                    u += 1;
                }
            }
            if(j != 0)
            {
                l = ans[i][j-1];
                if(mat[i][j-1] == '.'
                && mat[i][j] == '#')
                {
                    l += 1;
                }
            }
            
            ans[i][j] = min(u,l);
        }
    }
    cout << ans[h-1][w-1] << endl;
}