#include <bits/stdc++.h>
using namespace std;
#define int long long
int inf = 10e17;
#define mod 1000000007
// int findLowerBound(
//     vector<pair<int, int>> &arr,
//     pair<int, int> &p)
// {

//     auto low = lower_bound(arr.begin(),
//                            arr.end(), p);

//     return low - arr.begin();
// }
// int findUpperBound(
//     vector<pair<int, int>> &arr,
//     pair<int, int> &p)
// {
//     auto up = upper_bound(arr.begin(),
//                           arr.end(), p);

//     return up - arr.begin();
// }
// bool vis[200005];
// vector<int> vec[2000005];
// int child[2000005];
// int parent[2000005];
// int div1[100005];
// void dfs(int node)
// {
//     vis[node] = 1;
//     for (int i = 0; i < vec[node].size(); i++)
//     {
//         if (!vis[vec[node][i]])
//         {
//             parent[vec[node][i]] = node;
//             dfs(vec[node][i]);
//             //   child[node] += child[vec[node][i]];
//         }
//     }
// }
// void bfs(int node)
// {
//     queue<int> qu;
//     qu.push(node);
//     vis[1] = 1;
//     while (!qu.empty())
//     {
//         int top = qu.front();
//         //cout << qu.front() << "\n";
//         qu.pop();
//         vis[top] = 1;
//         for (int i = 0; i < vec[top].size(); i++)
//         {
//             if (!vis[vec[top][i]])
//             {
//                 parent[vec[top][i]] = top;
//                 qu.push(vec[top][i]);
//                 vis[vec[top][i]] = 1;
//             }
//         }
//     }
// }
// void belman(int n, int m, vector<pair<int, pair<int, int>>> vec, int dis[])
// {
//     for (int i = 0; i <= n + m - 1; i++)
//     {
//         for (int j = 0; j < vec.size(); j++)
//         {
//             int u = vec[j].second.first;
//             int v = vec[j].second.second;
//             int w = vec[j].first;

//             if (dis[u] + w < dis[v])
//             {
//                 dis[v] = dis[u] + w;
//             }
//         }
//     }
// }
// int fun(int a, int b)
// {
//     if (a > b)
//         return 0;
//     if (a == b)
//         return 1;
//     else
//     {
//         return fun(a + 1, b) + fun(a, b - a);
//     }
// }

// Required function
int32_t main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    //string str;
    //cin >> str;
    //  int n = str.length();
    int n;
    cin >> n;
    // int ans = 0;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    vector<int> vec;
    int carry = 0;
    for (int i = 0; i <= 100; i++)
    {
        int one = 0;

        for (int j = 0; j < n; j++)
        {
            if (arr[j] & 1)
                one++;
            arr[j] /= 2;
        }
        int p = one * (n - one);
        // ans = (ans + (((int)pow(2, 61 - i) % mod) * p) % mod) % mod;
        int sum = p + carry;
        vec.push_back(sum % 2);
        carry = sum / 2;
    }
    int ans = 0;
    int sum = 1;
    for (int i = 0; i < vec.size(); i++)
    {
        ans = (ans + vec[i] * sum) % mod;
        sum = (sum * 2) % mod;
    }
    cout << ans << "\n";

    return 0;
}
