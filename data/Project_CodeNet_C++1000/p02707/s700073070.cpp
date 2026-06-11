#include <bits/stdc++.h>
typedef long long ll;

#define rep(i, a, b) for (int i = a; i < (ll)b; ++i)
#define INF 10e12
#define MAX 51000
#define all(x) (x).begin(), (x).end()
#define MX(x) *max_element(all(x))
#define MN(x) *min_element(all(x))

using namespace std;

const long long MOD = 1e9 + 7;

int root_tree(vector<int> &v, int i)
{
    if (v[i] == i)
        return i;
    return root_tree(v, v[i]);
}
void union_tree(vector<int> &v, vector<int> &rank, int i, int j)
{
    int x = root_tree(v, i);
    int y = root_tree(v, y);
    if (rank[x] < rank[y])
        v[x] = y;
    else
        v[y] = x;
    if (rank[x] == rank[y])
        rank[x]++;
}
bool check_tree(vector<int> &v, int i, int j)
{
    if (root_tree(v, i) == root_tree(v, j))
        return true;
    return false;
}
int main(void)
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> v(n, 0);
    rep(i, 0, n - 1)
    {
        int temp;
        cin >> temp;
        v[--temp]++;
    }
    rep(i, 0, n) cout << v[i] << endl;
}