#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1001001001;
const ll LINF = 1001001001001001;
const int MOD = 1000000007;

template <typename T>
void print(const T &v);

int n;
vector<string> ans;

void dfs(string str)
{
    if (str.size() == n)
    {
        ans.push_back(str);
        return;
    }
    char maxi = 'a';
    for (char c : str)
    {
        maxi = max(c, maxi);
    }

    for (char i = 'a'; i <= maxi + 1; i++)
    {
        string tmp = str;
        tmp.push_back(i);
        dfs(tmp);
    }
}

int main()
{
    cin >> n;
    if (n == 1)
    {
        cout << 'a' << endl;
        return 0;
    }
    dfs("a");
    sort(ans.begin(), ans.end());
    for (string a : ans)
    {
        cout << a << endl;
    }
    return 0;
}

// Use For Debug
template <typename T>
void print(T const &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        if (i)
            cout << ' ';
        cout << v[i];
    }
    cout << endl;
};