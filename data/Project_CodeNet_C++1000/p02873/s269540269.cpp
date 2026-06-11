#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    cin >> s;
    vector<int> A(s.size() + 1);
    for (int i = 0; i < s.size(); ++i)
        if (s.at(i) == '<')
            A[i + 1] = max(A[i + 1], A[i] + 1);

    for (int i = s.size() - 1; i >= 0; --i)
        if (s.at(i) == '>')
            A[i] = max(A[i], A[i + 1] + 1);

    long long ans = 0;
    for (int i = 0; i <= s.size(); ++i)
        ans += A[i];
    cout << ans << endl;
    return 0;
}

