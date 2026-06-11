#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    for(int i=0; i<N; i++) cin >> A[i];

    int l = 1, r = 1e9;
    while(r - l > 1)
    {
        int cnt = 0;
        int mid = (l + r) / 2;
        for(int i=0; i<N; i++)
        {
            cnt += (A[i] - 1) / mid;
        }
        if(cnt <= K)
        {
            r = mid;
        }
        else
        {
            l = mid;
        }
    }
    {
        int cnt = 0;
        for(int i=0; i<N; i++)
        {
            cnt += (A[i] - 1) / l;
        }
        if(cnt <= K) r = l;
    }

    cout << r << endl;

    return 0;
}
