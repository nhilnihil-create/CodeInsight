#include<bits/stdc++.h>
using namespace std;
template <typename T> using vec = vector<T>;

int main()
{
    int n;
    cin >> n;
    vec<int> a(n),b(n),c(n-1);
    for (auto &&e : a)
    {
        cin >> e;
        e--;
    }
    for (auto &&e : b)
    {
        cin >> e;
    }
    for (auto &&e : c)
    {
        cin >> e;
    }
    int ans = 0;
    ans += b.at(a.at(0));
    for (int i = 1; i < n; i++)
    {
        ans += b.at(a.at(i));
        if (a.at(i-1) + 1 == a.at(i))
        {
            ans += c.at(a.at(i-1));
        }
    }
    cout << ans << endl;
}