#include <iostream>
using namespace std;
int ans = 0;
void find(int a[], int b[][16], int c[][16], int n, int x, bool used[])
{
    if(x == n + 1)
    {
        int sub = 0;
        bool wrong = false;
        for(int i = 1; i <= n; i++)
        {
            if(used[i])
            {
                sub++;
                for(int j = 0; j < a[i]; j++)
                {
                    if(used[b[i][j]] != c[i][j])
                    {
                        wrong = true;
                        return;
                    }
                }
            }
        }
        ans = max(sub, ans);
        return;
    }
    find(a, b, c, n, x + 1, used);
    used[x] = true;
    find(a, b, c, n, x + 1, used);
    used[x] = false;
}
int main()
{
    int n;
    cin >> n;
    int a[16], b[16][16], c[16][16];
    bool used[n + 1];
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        used[i] = false;
        for(int j = 0; j < a[i]; j++)
        {
            cin >> b[i][j] >> c[i][j];
        }
    }
    find(a, b, c, n, 1, used);
    cout << ans << endl;
    return 0;
}
