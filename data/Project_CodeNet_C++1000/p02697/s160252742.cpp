#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <cmath>
#include <iostream>
#include <stack>
#include <queue>

#define ll long long int
#define all(x) x.begin(), x.end()
#define MOD 998244353

using namespace std;



void solve()
{   
    int N, M;
    cin >> N >> M;

    int even_count = (M + 1) / 2;
    int odd_count = M / 2;

    int a = even_count;
    int b = a + 1;

    for (int i = 0; i < even_count; i++)
    {
        cout << a << " " << b << endl;
        a--;
        b++;
    }

    a =2 * even_count + odd_count;
    b = a + 2;

    for (int i = 0; i < odd_count; i++)
    {
        cout << a << " " << b << endl;
        a--;
        b++;
    }
}



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T = 1;
    // cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}

