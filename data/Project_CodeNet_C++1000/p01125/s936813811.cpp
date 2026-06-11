#include <iostream>
using namespace std;
#define MAX 21

int main()
{
    int n, m, x, y, i, j, dis, res;
    int gems[MAX][MAX];
    char dir;
    while (cin >> n, n) {
        for (i = 0; i < MAX; ++i)
            for (j = 0; j < MAX; ++j)
                gems[i][j] = 0;
        for (i = 0; i < n; ++i) {
            cin >> x >> y;
            gems[x][y] = 1;
        }
        x = y = 10;
        res = gems[x][y];
        cin >> m;
        for (i = 0; i < m; ++i) {
            cin >> dir >> dis;
            if (dir == 'N')
                for (j = 0; j < dis; ++j) {
                    res += gems[x][++y];
                    gems[x][y] = 0;
                }
            if (dir == 'E')
                for (j = 0; j < dis; ++j) {
                    res += gems[++x][y];
                    gems[x][y] = 0;
                }
            if (dir == 'S')
                for (j = 0; j < dis; ++j) {
                    res += gems[x][--y];
                    gems[x][y] = 0;
                }
            if (dir == 'W')
                for (j = 0; j < dis; ++j) {
                    res += gems[--x][y];
                    gems[x][y] = 0;
                }
        }
        if (res == n)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}