#include<bits/stdc++.h>
using namespace std;

int N;
int ans[510][510];

void unit(int l, int r, int d = 1)
{
    if(l + 1 == r)return;

    int mid = (l + r) / 2;

    for(int i = l; i < mid; i++)
        for(int j = mid; j < r; j++)
            ans[i][j] = d;

    unit(l, mid, d + 1);
    unit(mid, r, d + 1);
}

int main()
{
    cin >> N;

    unit(0, N);

    for(int i = 0; i < N; i++)
    {
        for(int j = i + 1; j < N; j++)
        {
            cout << ans[i][j];
            if(j != N - 1)cout << " ";
        }
        cout << endl;
    }

    return 0;
}
