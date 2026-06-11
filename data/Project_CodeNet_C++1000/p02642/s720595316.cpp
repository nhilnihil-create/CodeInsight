#include <iostream>

using namespace std;

const int Max = 1e6 + 5, Nmax = 2e5 + 5;
int H[Max],a[Nmax];
int N, ans;
bool OK;

int main()
{
    cin >> N;

    for(int i = 1; i <= N; ++i)
    {
        cin >> a[i];
        H[a[i]]++;
    }

    if(H[1])
        return cout << (H[1] == 1 ? 1 : 0), 0;

    for(int i = 1; i <= N; ++i)
    {
        OK = 1;

        if(H[a[i]] > 1)
            OK = 0;

        for(int j = 2; j * j <= a[i] && OK; ++j)
        {
            if(a[i] % j == 0 && H[j])
                OK = 0;

            if(a[i] % (a[i] / j) == 0 && H[a[i] / j])
                OK = 0;
        }

        ans += OK;
    }

    cout << ans;
    return 0;
}
