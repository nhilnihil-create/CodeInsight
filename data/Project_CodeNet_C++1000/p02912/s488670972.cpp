#include<bits/stdc++.h>
using namespace std;

#define int long long

int N, M;
vector<int> V(10);
int ans;

signed main()
{
    cin >> N >> M;
    for(int i = 0; i < N; i++)
    {
        int a;
        cin >> a;
        ans += a;
        int tmp = 1;
        for(int j = 0; j < 50; j++)
        {
            V.push_back(a / tmp - a / (tmp * 2));
            tmp *= 2;
        }
    }

    sort(V.rbegin(), V.rend());
    for(int i = 0; i < min(M, (int)V.size()); i++)
        ans -= V[i];

    cout << ans << endl;

    return 0;
}