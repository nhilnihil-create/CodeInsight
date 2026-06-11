#include <bits/stdc++.h>


using namespace std;

int main()
{

    int m,n,x,y, ans = 0;
    cin >> n >> m;
    vector<int> q[n+1];
    for (int i = 0 ; i < m ; ++ i)
    {
        cin >> x >> y;
        q[x].push_back(y);
        q[y].push_back(x);
    }
    vector<bool> used(n+2,0);
    for (int i = 1; i <= n ; ++i)
    {
        if (!used[i])
        {
            used[i] = true;
            ans ++;
            queue<int> a;
            a.push(i);
            while(!a.empty())
            {
                int d = a.front();
                a.pop();
                for (int &w:q[d])
                {
                    if (!used[w])
                    {
                        used[w] = true;
                        a.push(w);
                    }

                }
            }
        }

    }cout << ans - 1;
    return 0;
}
