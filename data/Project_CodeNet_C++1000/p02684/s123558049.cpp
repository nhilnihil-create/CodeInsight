#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using Graph = vector<vector<int>>;

int main(void)
{
    int n;
    ll k;
    cin >> n >> k;
    vector<int> a(n);
    vector<bool> seen(n,false);
    deque<int> path;
    for(int i=0;i<n;++i)
    {
        cin >> a[i];
        --a[i];
    }
    int x=0;
    while(true)
    {
        if(seen[x])
        {
            while(path[0]!=x)
            {
                path.pop_front();
                --k;
                if(k==0)
                {
                    cout << path[0]+1 << endl;
                    return 0;
                }
            }
            break;
        }
        seen[x]=true;
        path.push_back(x);
        x=a[x];
    }
    
    cout << path[k%path.size()]+1 << endl;
    return 0;
}
