#include <bits/stdc++.h>

#define REP(i, n) for(int (i)=0;(i)<(n);++(i))
#define REPV(iter, v) for(auto (iter)=(v).begin(); (iter)!=(v).end();++(iter))
#define ALL(v) (v).begin(),(v).end()

#define MOD 1000000007

using namespace std;

typedef long long ll;

int main()
{
    ll N;
    cin >> N;
    vector<ll> a(N);
    REP(i, N)
    {
        cin >> a[i];
    }

    bool isMake = true;
    ll kind = 0;
    map<ll, ll> countMap;
    REP(i, N)
    {
        if (countMap.find(a[i]) == countMap.end())
        {
            countMap[a[i]] = 1;
            kind++;
        }
        else
        {
            countMap[a[i]]++;
        }
        if (kind >= 4)
        {
            isMake = false;
            break;
        }
    }

    if (isMake)
    {
        if (kind == 1)
        {
            if (countMap[0] != N)
            {
                isMake = false;
            }
        }
        else if (kind == 2)
        {
            if ( !(N % 3 == 0 && countMap[0] == N / 3) )
            {
                isMake = false;
            }
        }
        else if (kind == 3)
        {
            if (N % 3 != 0)
            {
                isMake = false;
            }
            vector<ll> numV;
            REPV(it, countMap)
            {
                numV.push_back(it->first);
            }
            ll a = numV[0], b = numV[1], c = numV[2];
            if ( !(countMap[a] == countMap[b] && countMap[a] == countMap[c]) )
            {
                isMake = false;
            }
            if ((a ^ b) != c)
            {
                isMake = false;
            }
        }
    }

    string ans = isMake ? "Yes" : "No";

    cout << ans << endl;
}
