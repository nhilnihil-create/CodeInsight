#include <bits/stdc++.h>
#define PI 3.1415926535897
using namespace std;
typedef long long ll;
const int INF = 1000000000;
const ll LINF = 1000000000000000000; //1e18
const double EPS = 1e-10;

// 単調非減少 always a[i] <= a[i + 1]
int main(void)
{
    int N;
    cin >> N;

    vector<int> H(N);
    for (int i = 0; i < N; i++)
    {
        cin >> H[i];
    }

    for (int i = 0; i < N - 1; i++)
    {
        if (H[i] < H[i + 1])
        {
            H[i + 1]--;
        }
    }

    bool isFine = true;
    for (int i = 0; i < N - 1; i++)
    {
        if (H[i] > H[i + 1])
        {
            isFine = false;
            break;
        }
    }

    if (isFine == true)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }

    return (0);
}
