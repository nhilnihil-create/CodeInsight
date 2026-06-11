#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    int M1, M2, D1, D2;
    cin >> M1 >> D1 >> M2 >> D2;
    bool A = ((M1 + 1) == M2) && D2 == 1;

    cout << (A ? 1 : 0) << endl;
}
