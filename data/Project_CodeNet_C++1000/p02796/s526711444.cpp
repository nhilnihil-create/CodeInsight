#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int MAX_N = 100000;
const int MAX_V = 1000000000;

int main()  {
    int n;
    ll x,l,ans=0,cur=-MAX_V;
    cin>>n;
    set<pair<int,int>> s;
    for(int i=0;i<n;i++)
    {
        cin>>x>>l;
        s.insert(make_pair(x+l,x-l));
    }
    //sort(s.begin(),s.end());
    for(auto i:s)
    {
        if(cur<=i.second)
        {
            ans++;
            cur=i.first;
        }
    }
    cout<<ans;
    return 0;
}
