#include <iostream>
#include <bitset>
#include <algorithm>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
using LD = long double;
using pii = pair<int, int>;
using pll = pair<LL, LL>;
int A[12][12], row_price[12], alg_und[12];
int N, M, X;
int min_price = 1e9;
bitset<12> is_done_alg;


void solve(const int &cur_row, const int &cur_price)
{
    if (is_done_alg.count() == M)
    {
        min_price = min(min_price, cur_price);
        return;
    }
    if (cur_row == N)
    {
        return;
    }
  
    solve(cur_row + 1, cur_price);

    for (int j = 0; j < M; ++j)
    {
        alg_und[j] += A[cur_row][j];
        if (alg_und[j] >= X)
        {
            is_done_alg[j] = true;
        }
    }

    solve(cur_row + 1, cur_price + row_price[cur_row]);

    for (int j = 0; j < M; ++j)
    {
        alg_und[j] -= A[cur_row][j];
        if (alg_und[j] < X)
        {
            is_done_alg[j] = false;
        }
    }
}


int main()
{
    cin.sync_with_stdio(0);

    cin >> N >> M >> X;

    for (int i = 0; i < N; ++i)
    {
        cin >> row_price[i];

        for (int j = 0; j < M; ++j)
        {
            cin >> A[i][j];
        }
    }

    solve(0, 0);

    cout << (min_price == 1e9 ? -1 : min_price);
}
