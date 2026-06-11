#include <bits/stdc++.h>
using namespace std;
template <typename Container>
void print(const Container &c, char end = '\n', char sep = ' ')
{
    for (const auto &x : c)
        cout << x << sep;
    cout << end;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    for (int i = 0; i < n; i++)
    {
        cout << s[i] << t[i];
    }

    return 0;
}