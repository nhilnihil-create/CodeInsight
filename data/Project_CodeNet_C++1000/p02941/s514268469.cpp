#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, int>;
ll INF = 1e9+7;
int main()
{
    int n;
    cin >> n;
    vector<ll> a(n+1);
    vector<ll> b(n+2);
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    priority_queue<P> que;
    for(int i = 1; i <= n; i++)
    {
        cin >> b[i];
        que.push(P(b[i], i));
    }
    b[0] = b[n];
    b[n+1] = b[1];
    ll ans = 0;
    while(que.size())
    {
        P p1 = que.top();
        que.pop();
        ll pos = p1.second;
              if(p1.first == a[pos]) continue;
        ll cand, up1;
        ll dec = b[pos-1] + b[pos+1];
        if(p1.first <= dec)
        {
          cout << -1 << endl;
          return 0;
        }
        if(que.size() == 0)
        {
            cand = a[pos];
            ll x = p1.first - cand;
            up1 = p1.first - dec * (x/dec);
            ans += (x/dec);
            if(x % dec != 0)
            {
                cout << -1 << endl;
                return 0;
            }
            else
            {
              cout << ans << endl;
              return 0;
            }
        }
        else
        { 
            P p2 = que.top();
            cand = max(dec, a[pos]);
            ll x = p1.first - cand;
            x--;
            up1 = p1.first - dec * (x/dec + 1);
            ans += (x/dec + 1);
        }
        if(up1 < a[pos])
        {
            cout << -1 << endl;
            return 0;
        }
        else
        {
            b[pos] = up1;
            if(pos == n) b[0] = b[pos];
            if(pos == 1) b[n+1] = b[pos];
            if(a[pos] != b[pos])
            {
                que.push(P(b[pos], pos));
            }
        }
    }
    cout << ans << endl;
}

