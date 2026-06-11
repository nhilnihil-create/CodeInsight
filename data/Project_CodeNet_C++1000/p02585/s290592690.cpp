#include<bits/stdc++.h>

#define fi first
#define se second
#define pb push_back
 
#define limit (int) (2e5 + 5) 
#define mod (long long int) (1e9 + 7)
 
using namespace std;
using lli = long long int;
using ulli = unsigned long long int;
using ld = long double;

int p[5005],c[5005];
bool visited[5005] = {};

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n,k;
    cin >> n >> k;

    for (int i = 1; i <= n; ++i)
    {
        cin >> p[i];
    }

    for (int i = 1; i <= n; ++i)
    {
        cin >> c[i];
    }

    lli ans = LLONG_MIN,temp,s;

    vector<int> v;
    int ck,ps;

    for (int i = 1; i <= n; ++i)
    {
        if(visited[i]) continue;
        s = 0;
        int ci = i;
        v.clear();
        while(!visited[ci])
        {
            visited[ci] = true;
            v.pb(ci);
            s += c[ci];
            ci = p[ci];
        }

        ps = v.size();

        // for(auto e:v)
        //     cout << e;
        // cout << "\n";

        temp = 0;
        if (s < 0)
        {
            ck = min(k,ps);
        } else {

            if (k > ps)
            {
                ck = ps + k%ps;
                temp = (k/ps - 1)*s;
            } else {
                ck = k;
            }
        }

        // cout << ck << " " << temp << "\n";

        lli sum;

        for (int j = 0; j < ps; ++j)
        {
            sum = 0;
            for (int k = 0; k < ck; ++k)
            {
                sum += c[v[(j+k)%ps]];
                ans = max(ans,sum+temp);
            }
        }
    }

    cout << ans;

    return 0;

}












