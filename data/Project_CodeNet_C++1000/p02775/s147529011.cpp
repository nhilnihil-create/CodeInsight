#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <map>
#include <set>
#include <vector>
#include <utility>
#include <queue>
#include <cmath>

#define BEGIN(x) x.begin()
#define END(x) x.end()
#define ALL(x) BEGIN(x), END(x)
#define PAIR make_pair
#define VEC(type) vector<type >

using namespace std;

typedef long long lint;

void io_init()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
};

string S;
int dp[1 << 20][10];

int f(int i, int carry)
{
    if (i == -1)
        return carry;
    int& ans = dp[i][carry];
    if (ans >= 0)
        return ans;
    ans = 100 * 1000000;
    int digit = S[i] - '0';
    for (int d = 0;d < 10; d++)
        ans = min(ans, d + (digit + carry + d) % 10 + 
                    f(i - 1, (digit + carry + d) / 10));

    return ans;
};

int main(int argc, char **argv)
{
    io_init();

    // Actual program code starts here.
    cin >> S;
    memset(dp, -1, sizeof dp);
    cout << f(S.size() - 1, 0) << endl;
    return 0;
};
