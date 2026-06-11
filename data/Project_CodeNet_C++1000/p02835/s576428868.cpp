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
int maxProductSubarrayOfSizeK(int A[], int n, int k)
{
    // sorting given input array
    sort(A, A + n);

    // variable to store final product of all element
    // of sub-sequence of size k
    int product = 1;

    // CASE I
    // If max element is 0 and
    // k is odd then max product will be 0
    if (A[n - 1] == 0 && (k & 1))
        return 0;

    // CASE II
    // If all elements are negative and
    // k is odd then max product will be
    // product of rightmost-subarray of size k
    if (A[n - 1] <= 0 && (k & 1))
    {
        for (int i = n - 1; i >= n - k; i--)
            product *= A[i];
        return product;
    }

    // else
    // i is current left pointer index
    int i = 0;

    // j is current right pointer index
    int j = n - 1;

    // CASE III
    // if k is odd and rightmost element in
    // sorted array is positive then it
    // must come in subsequence
    // Multiplying A[j] with product and
    // correspondingly changing j
    if (k & 1)
    {
        product *= A[j];
        j--;
        k--;
    }

    // CASE IV
    // Now k is even
    // Now we deal with pairs
    // Each time a pair is multiplied to product
    // ie.. two elements are added to subsequence each time
    // Effectively k becomes half
    // Hence, k >>= 1 means k /= 2
    k >>= 1;

    // Now finding k corresponding pairs
    // to get maximum possible value of product
    for (int itr = 0; itr < k; itr++)
    {

        // product from left pointers
        int left_product = A[i] * A[i + 1];

        // product from right pointers
        int right_product = A[j] * A[j - 1];

        // Taking the max product from two choices
        // Correspondingly changing the pointer's position
        if (left_product > right_product)
        {
            product *= left_product;
            i += 2;
        }
        else
        {
            product *= right_product;
            j -= 2;
        }
    }

    // Finally return product
    return product;
}
int32_t main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);
    int a, b, c;
    cin >> a >> b >> c;
    int p = a + b + c;
    if (p >= 22)
        cout << "bust"
             << "\n";
    else
    {
        cout << "win"
             << "\n";
    }

    return 0;
}
