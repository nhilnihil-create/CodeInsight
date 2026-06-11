#include <iostream>
#include <vector>
#include <deque>
#include <numeric>
#include <algorithm>
#include <cmath>
#include <climits>

constexpr int SINT_MAX = std::numeric_limits<int>::max();
constexpr int SINT_MIN = std::numeric_limits<int>::min();

using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;

///////////////////////////////////////////////////

int main()
{
    int N, M;
    string S;
    cin >> N >> M >> S;
    
    vi grid(N+1);
    for (int i = 0; i <= N; ++i)
    {
        grid[i] = (S[i] == '0') ? 0 : -1;
    }
    
    int i = 0;
    deque<int> list;
    while (i < N)
    {
        bool canpass = false;
        for (int m = M; m >= 1 && !canpass; --m)
        {
            if (i + m <= N && grid[N - i - m] == 0)
            {
                i += m;
                list.push_front(m);
                canpass = true;
            }
        }
        if (!canpass)
        {
            cout<< -1 << endl;
            return 0;
        }
    }
    
    for (int d : list)
    {
        cout << d << " ";
    }
    cout << endl;

    /*
    vi dp(N+1, N);
    dp[N] = 0;
    for (int i = N; i >= 0; --i)
    {
        for (int m = 1; m <= M; ++m)
        {
            if (i >= m && grid[i-m] != -1 && dp[i-m] >= dp[i] + 1)
            {
                dp[i-m] = dp[i] + 1;
                grid[i-m] = i;
            }
        }
    }

    if (grid[0] == 0)
    {
        cout << "-1" << endl;
    }
    else
    {
        for(int i = 0; i < N; i = grid[i])
        {
            cout << (grid[i] - i) << " ";
        }
        cout << endl;
    }
    */
}