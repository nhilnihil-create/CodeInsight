#include <bits/stdc++.h>
using namespace std;

int main()
{
    string T;
    cin >> T;

    string ans;
    for (int i = 0; i < T.size(); i++) {
        ans += T[i] == 'P' ? 'P' : 'D';
    }
    cout << ans << endl;
}