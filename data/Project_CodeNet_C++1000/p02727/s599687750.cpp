#include<bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i,n) for(int i=0;i<(n);i++)

int X, Y, A, B, C;
priority_queue<int, vector<int>, greater<int>> pq;
vector<int> a, b, c;

int ans;
int max_ans = 0;

void update(int x)
{
    if(pq.size() != Y)
    {
        ans += x;
        pq.push(x);
    }
    else
    {
        int v = pq.top();
        pq.pop();
        ans -= v;
        x = max(x, v);
        pq.push(x);
        ans += x;
    }
}

signed main()
{
    cin >> X >> Y >> A >> B >> C;

    int v;
    rep(i, A)
    {
        cin >> v;
        a.push_back(v);
    }
    rep(i, B)
    {
        cin >> v;
        b.push_back(v);
    }
    rep(i, C)
    {
        cin >> v;
        c.push_back(v);
    }

    sort(a.rbegin(), a.rend());
    sort(b.rbegin(), b.rend());
    sort(c.rbegin(), c.rend());

    int aa = max(X - C, 0ll), cc = min(X, C);

    rep(i, B)update(b[i]);
    rep(i, C)
    {
        if(i < cc)ans += c[i];
        else update(c[i]);
    }
    max_ans = ans;
    rep(i, min(X, A))
    {
        if(i < aa)ans += a[i];
        else
        {
            ans += a[i];
            ans -= c[cc - 1 - (i - aa)];
            update(c[cc - 1 - (i - aa)]);
        }
        max_ans = max(ans, max_ans);
    }

    cout << max_ans << endl;

    return 0;
}
