#include <bits/stdc++.h>

using namespace std;

int n, k;
int a[200000];
map<int, vector<int>> e;
long long ans = 0;

int main()
{
  	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

    cin >> n >> k;

    e[0].push_back(0);
    int t, sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> t;
        sum = (sum + t) % k;
        a[i] = ((sum - i - 1) % k + k)%k;
        e[a[i]].push_back(i + 1);
    }

    for (auto a : e)
    {
        int tail = 0;
        for (int i = 1; i < a.second.size(); i++)
        {
            while (a.second[i] - a.second[tail] >= k)
                tail++;

            ans += i - tail;
        }
    }

    cout << ans;

	return 0;
}
