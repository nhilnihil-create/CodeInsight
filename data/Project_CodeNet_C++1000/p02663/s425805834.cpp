#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int retNum(const char r)
{
    switch (r)
    {
    case 'A':
        return 4;

    case 'B':
        return 3;

    case 'C':
        return 2;

    case 'D':
        return 1;

    default:
        return 0;
    }
}
int main()
{
    int H1, M1, H2, M2, K;
    cin >> H1 >> M1 >> H2 >> M2 >> K;
    cout << (H2 - H1) * 60 + M2 - M1 - K << endl;
}
