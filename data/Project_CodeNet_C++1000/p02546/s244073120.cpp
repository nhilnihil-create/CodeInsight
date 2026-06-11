#include <bits/stdc++.h>
using namespace std;

int main()
{
    string S; cin >> S;
    int n = S.size() - 1;
    if (S[n] == 's')
        cout << S << "es" << '\n';
    else cout << S << "s" << '\n';
}
