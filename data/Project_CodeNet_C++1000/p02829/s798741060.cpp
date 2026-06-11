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
    int a, b;
    cin >> a >> b;
    cout << 6 - a - b;

    return 0;
}