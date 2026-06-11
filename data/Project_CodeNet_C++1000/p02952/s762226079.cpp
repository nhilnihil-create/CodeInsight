#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = unsigned long long;
using p = pair<int, int>;

int main()
{
    int N;
    cin >> N;

    int count = 0;

    while (N != 0)
    {
        if (to_string(N).length() % 2 != 0)
        {
            ++count;
        }
        N -= 1;
    }

    std::cout << count << endl;
    return 0;
}
