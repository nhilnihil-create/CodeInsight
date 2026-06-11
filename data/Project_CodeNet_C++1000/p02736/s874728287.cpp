#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MAXN = 1000100;

int N;
int arr[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);

    cin >> N;

    int cres = 0, ck = 0;
    for (int i = 0; i < N; i++)
    {
        char c; cin >> c;
        arr[i] = c - '1';

        if (arr[i] == 1) ck = -1e9;

        if (((N-1) & i) == i)
        {
            //cout << i << " " << arr[i] << "\n";
            cres = (cres + arr[i]) % 2;
            ck = (ck + arr[i] / 2);
        }
    }

    if (ck >= 0)
        cout << 2 * (ck % 2) << "\n";
    else
        cout << cres % 2 << "\n";
}