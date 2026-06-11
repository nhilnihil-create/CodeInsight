#include <bits/stdc++.h>
using namespace std;

int64_t MOD = 1000000007;
int64_t MAX = 9223372036854775807;
double PI = 3.141592653589793;

pair<int, int> AB(int64_t N)
{
    int p;
    p = N % 10;
    while (N >= 10)
    {
        N /= 10;
    }
    pair<int, int> tmp(p, N);
    return tmp;
}

int main()
{
    int N;
    cin >> N;
    vector<vector<int>> list(10, vector<int>(10, 0));
    for (int i = 1; i <= N; i++)
    {
        auto tmp = AB(i);
        int p = tmp.first, q = tmp.second; //末尾、先頭
        list[p][q]++;
    }
    int ans = 0;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            ans += list[i][j] * list[j][i];
        }
    }
    cout << ans;
}