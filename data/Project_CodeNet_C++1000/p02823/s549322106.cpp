#include <iostream>
#include <algorithm>
#include <tuple>
#include <vector>
#include <string>

using namespace std;

int64_t n, a, b;
int64_t ans = 0;

int main(int argc, char const *argv[])
{
    cin >> n >> a >> b;
    if ((b - a) % 2 == 0)
    { //2人のテーブルが奇数個離れている
        ans = (b - a) / 2;
    }
    else if ((b - a) % 2 == 1)
    {
        ans = min(a - 1, n - b) + 1 + (b - a - 1) / 2;
    }

    cout << ans << endl;
    return 0;
}
