#include <bits/stdc++.h>
using namespace std;
#define FASTIO                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)
#define MOD 1000000007
int main()
{
    int n,x;
    cin>>n;
    n = (1<<n);
    multiset<int>arr;
    for(int i=0; i<n; i++) cin>>x,arr.insert(x);
    multiset<int>done,temp;
    done.insert(*arr.rbegin());
    arr.erase(arr.find(*arr.rbegin()));

    for(int i=1; i<n; i=i<<1)
    {
        for(auto it=done.begin(); it!=done.end(); it++)
        {
            auto bt = arr.lower_bound(*it);
            if(bt == arr.begin())
            {
                cout<<"No";
                exit(0);
            }

            bt--;
            temp.insert(*bt);
            arr.erase(bt);
        }
        for(auto x:temp) done.insert(x);
        temp.clear();
    }
    cout<<"Yes";
}