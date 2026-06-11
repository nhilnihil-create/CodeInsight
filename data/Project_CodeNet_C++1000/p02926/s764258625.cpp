#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, I;
    cin >> n;
    long double X[n], Y[n], an, SX[n+1], SY[n+1], sx, sy, M=0;
    vector <pair<long double,int>> V;
    for (int i = 0; i < n; i++)
    {
        cin >> X[i] >> Y[i];
        an = atan2(X[i],Y[i]);
        V.push_back({an,i});
    }
    sort(V.begin(),V.end());
    SX[0] = 0;
    SY[0] = 0;
    for (int i = 0; i < n; i++)
    {
        I = V[i].second;
        SX[i+1] = SX[i] + X[I];
        SY[i+1] = SY[i] + Y[I];
    }
    for (int i = 1; i <= n; i++)
    {
        for (int y = 1; y <= n; y++)
        {
            if (i <= y)
            {
                sx = SX[y] - SX[i-1];
                sy = SY[y] - SY[i-1];
            }
            else
            {
                sx = SX[y] + SX[n] - SX[i-1];
                sy = SY[y] + SY[n] - SY[i-1];
            }
            M = max(M, sqrt(sx*sx + sy*sy));
        }
    }
    cout << fixed << setprecision(11) << M;
    return 0;
}
