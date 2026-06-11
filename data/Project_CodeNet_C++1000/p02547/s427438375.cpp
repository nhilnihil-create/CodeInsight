#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<int> A(N);
    vector<int> B(N);
    string ans = "No";

    for (int i = 0; i < N; i++)
    {
        cin >> A.at(i) >> B.at(i);
    }

    for (int i = 0; i < N - 2; i++)
    {
        if (A.at(i) == B.at(i) && A.at(i + 1) == B.at(i + 1) && A.at(i + 2) == B.at(i + 2))
        {
            ans = "Yes";
        }
    }

    cout << ans << endl;
}
