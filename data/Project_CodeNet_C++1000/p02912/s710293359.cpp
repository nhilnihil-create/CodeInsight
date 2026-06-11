#include <bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
typedef long long ll;

int main()
{
    FAST;

    ll n,m;
    cin>>n>>m;

    ll arr[n];
    priority_queue<ll> q;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        q.push(arr[i]);
    }

    ll i = 0;
    while(i<m)
    {
        ll tmp = q.top();
        q.pop();
        tmp/=2;
        if(tmp!=0)
        q.push(tmp);

        if(q.empty())
            break;
        i++;
    }

    ll sum = 0;
    while(!q.empty())
    {
        sum+=q.top();
        q.pop();
    }

    cout<<sum<<endl;




    return 0;
}
