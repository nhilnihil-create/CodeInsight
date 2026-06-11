#include <bits/stdc++.h>
using namespace std;
int main()
{
    int N, M;
    while (1)
    {
        cin >> N >> M;
        if (N == 0 && M == 0)
            return 0;
        long long H[N], W[M];
        for (int i = 0; i < N; i++)
        {
            cin >> H[i];
        }
        for (int i = 0; i < M; i++)
        {
            cin >> W[i];
        }
        long long S_H[N + 1] = {0};
        long long S_W[M + 1] = {0};
        for (int i = 0; i < N; i++)
        {
            S_H[i + 1] = S_H[i] + H[i];
        }
        for (int i = 0; i < M; i++)
        {
            S_W[i + 1] = S_W[i] + W[i];
        }
        map<long, long> x, y;
        for (int i = 0; i <= N; i++)
        {
            for (int j = 0; j <= N; j++)
            {
                if (i < j)
                    x[S_H[j] - S_H[i]]++;
            }
        }
        for (int i = 0; i <= M; i++)
        {
            for (int j = 0; j <= M; j++)
            {
                if (i < j)
                    y[S_W[j] - S_W[i]]++;
            }
        }
        long long cnt = 0;
      	for(auto p:x){
          cnt+=x[p.first]*y[p.first];
        }
        cout << cnt << endl;
    }
}
