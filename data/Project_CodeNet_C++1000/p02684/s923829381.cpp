#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll visited[200005];

int main()
{
    ll n,k;
    cin>>n>>k;
    ll a[n+5],freq[n+5];
    for(int i=1; i<=n; i++)
    {
        cin>>a[i];
        freq[i]=-1;
    }
    visited[1]=1;
    freq[1]=0;
    ll now=1,cnt=1;

    //cycle
    while(1)
    {
        if(visited[a[now]])
            break;
        now=a[now];
        visited[now]=1;
        freq[now]=cnt;
        cnt++;
    }

    if(k>=cnt)
    {
        ll diff=cnt-freq[a[now]];
        k-=freq[a[now]];
        k%=diff;
        k+=freq[a[now]];
    }
    for(int i=1; i<=n; i++)
    {
        if(freq[i]==k)
        {
            cout<<i<<endl;
            break;
        }
    }
    return 0;
}
