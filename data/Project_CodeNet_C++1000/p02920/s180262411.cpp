#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 1e5;
const int INF = 1e9+1;
bool solve()
{
    set<pair<int,int>> done;
    set<pair<int,int>> not_done;
    int n; cin >> n;
    for(int i = 0; i < (1<<n); i++)
    {
        int x; cin >> x;
        not_done.insert({x,i});
    }

    done.insert(*--not_done.end());
    not_done.erase(--not_done.end());

    for(int i = 0; i < n; i++)
    {
        set<pair<int,int>> pending;
        for(const auto&  p : done)
        {
            auto x = not_done.upper_bound({p.first-1,INF});  
            if(x==not_done.begin())
                return false;
            else
            {
                pending.insert(*(--x));
                not_done.erase(x);
            }
        }
        for(const auto& p : pending)
            done.insert(p);
    }
    return true;
}
int main()
{
    cout<<(solve() ? "Yes" : "No")<<endl;
    return 0;
}