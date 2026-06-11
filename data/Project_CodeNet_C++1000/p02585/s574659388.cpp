#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll INF = 1LL << 60;

template<class T> inline bool chmax(T &a, T b)
{
    if(a < b)
    {
        a = b;
        return true;
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, K;
    cin >> N >> K;
    vector<int> P(N);
    for(int i=0; i<N; i++)
    {
        cin >> P[i];
        P[i]--;
    }
    vector<int> C(N);
    for(int i=0; i<N; i++) cin >> C[i];

    ll ans = -INF;
    for(int i=0; i<N; i++)
    {
        int start = i;
        int now = P[start];
        ll lans = 0;
        int cnt = 1;
        for(; cnt<=K; cnt++)
        {
            lans += C[now];
            chmax(ans, lans);
            if(now == start) break;
            now = P[now];
        }
        chmax(ans, lans);
        if(K % cnt != 0)
        {
            lans *= K / cnt;
            cnt = K - (K % cnt) + 1;
        }
        else
        {
            lans *= K / cnt - 1;
            cnt = K - (K % cnt) - cnt + 1;
        }
        
        for(; cnt<=K; cnt++)
        {
            now = P[now];
            lans += C[now];
            chmax(ans, lans);
        }
        chmax(ans, lans);
    }
    cout << ans << endl;

    return 0;
}
