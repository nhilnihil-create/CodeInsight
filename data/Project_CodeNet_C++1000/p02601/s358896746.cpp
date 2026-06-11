#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    int A, B, C;
    int K;
    cin >> A >> B >> C;
    cin >> K;

    for (int i = 0; i <= K; ++i)
    {
        if (A < B * pow(2, i) && B * pow(2, i) < C * pow(2, K - i))
        {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
}