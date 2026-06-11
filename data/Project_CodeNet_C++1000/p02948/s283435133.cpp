#include <bits/stdc++.h>

#define REP(i, n) for(int (i)=0;(i)<(n);++(i))
#define REPV(iter, v) for(auto (iter)=(v).begin(); (iter)!=(v).end();++(iter))
#define ALL(v) (v).begin(),(v).end()

#define MOD 1000000007

using namespace std;

typedef long long ll;

int main()
{
    ll N, M;
    cin >> N >> M;
    vector<ll> A(N), B(N);
    vector<pair<ll, ll>> work;
    REP(i, N)
    {
        cin >> A[i] >> B[i];
        work.push_back(make_pair(A[i], B[i]));
    }
    sort(ALL(work));
    ll ans = 0;
    ll day = M - 1;
    priority_queue<ll> q;
    ll index = 0;
    while(day != -1)
    {
        while(true)
        {
            if (index < N && work[index].first + day <= M)
            {
                q.push(work[index].second);
                index++;
            }
            else
            {
                break;
            }
        }
        if (!q.empty())
        {
            ans += q.top();
            q.pop();
        }
        day--;
    }

    cout << ans << endl;
}
