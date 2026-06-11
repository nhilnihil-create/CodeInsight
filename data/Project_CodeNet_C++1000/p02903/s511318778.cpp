#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
typedef long long int ll;
typedef pair<int, int> P;

int h, w, a, b;

int main()
{
    cin >> h >> w >> a >> b;
    int mat[h][w];
    rep(i, h)
    {
        rep(j, w)
        {
            mat[i][j] = ((j < a) ^ (i < b));
        }
    }
    rep(i, h) { rep(j, w) cout << mat[i][j]; cout << endl; }
    
    return 0;
}