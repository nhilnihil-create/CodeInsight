#include<bits/stdc++.h>
typedef long long ll;
const ll mod=1e9+7;
using namespace std;
priority_queue<int> q;
int main()
{
    int n,m;cin>>n>>m;
    int a;
    for(int i=0;i<n;i++)
    {
        cin>>a;
        q.push(a);
    }
    for(int i=0;i<m;i++)
    {
        a=q.top()/2;
        q.pop();
        q.push(a);
    }
    ll sum=0;
    while(!q.empty())
    {
        sum+=q.top();
        q.pop();
    }
    cout<<sum<<endl;
    return 0;
}
