#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double
#define sd second
#define ft first
#define ios                           \
    std::ios::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

const int MAX = 1e7 + 5;

int32_t main()
{
    ios;
    int n;
    cin >> n;
    vector<int> a(MAX, 1);
    for (int i = 2; i < MAX; i++)
    {
        for (int j = i; j < MAX; j += i)
        {
            a[j]++;
        }
    }
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        //int temp = sum;
        sum += (i * a[i]);
        // cout << sum - temp << " ";
    }
    //cout << endl;
    cout << sum << endl;
    return 0;
}