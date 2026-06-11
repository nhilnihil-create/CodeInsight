#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
int N, K;
vector<int> A(200100);

bool ok(int x)
{
    ll cnt = 0;
    for (int i = 0; i < N; i++)
    {
        if (A[i] > x)
            cnt += (A[i] - 1) / x;
    }
    if (cnt <= K)
        return true;
    return false;
}

int main()
{
    cin >> N >> K;
    for (int i = 0; i < N; i++)
        cin >> A[i];
    int l = 0, r = 1000000000;
    while (r - l > 1)
    {
        int m = (l + r) / 2;
        if (ok(m))
            r = m;
        else
            l = m;
    }
    cout << r << endl;
}
