#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <map>

using namespace std;
#define prev prev55

long long n, s, cnt;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        long long a, b;
        cin >> a >> b;
        s += a * b;
        cnt += b;
    }
    cout << cnt + (s - 1) / 9 - 1;
}
