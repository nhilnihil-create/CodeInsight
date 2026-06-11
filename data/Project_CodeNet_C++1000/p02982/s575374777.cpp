#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    int N, D;
    cin >> N >> D;
    int X[N][D];
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < D; j++)
        {
            X[i][j] = 0;
            cin >> X[i][j];
        }
        
    }
    
    int ans = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            long double dist = 0;
            for (int k = 0; k < D; k++)
            {
                dist += (X[i][k] - X[j][k]) * (X[i][k] - X[j][k]);
            }
            dist = sqrt(dist);
            if (floor(dist) == dist)
            {
                ans++;
            }
            

        }
        
    }
    cout << ans << endl;

  return 0;
}
