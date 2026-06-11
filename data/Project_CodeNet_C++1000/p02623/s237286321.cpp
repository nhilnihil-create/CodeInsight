#include <iostream>
#include<vector>

using namespace std;

int main()
{
    long long N, M, K; cin >> N >> M >> K;

    vector<long long> A(N), AS(N+1, 0), B(M), BS(M+1, 0);

    for(int i=0; i<N; ++i)
    {
        cin >> A[i];
        AS[i + 1] = AS[i] + A[i];
    }
    for(int i=0; i<M; ++i)
    {
        cin >> B[i];
        BS[i + 1] = BS[i] + B[i];
    }

    int an = 0, bn = 0, ans = 0;
    for(an = N; an >= 0; --an)
    {
        while(bn + 1 <= M && BS[bn + 1] <= K - AS[an]) ++bn;
        if(K >= AS[an] + BS[bn])
            ans = max(an + bn, ans);
    }

    cout << ans << endl;
}