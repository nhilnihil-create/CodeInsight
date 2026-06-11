#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ll K;
    cin >> K;
    queue<ll> que;
    que.push(1);
    que.push(2);
    que.push(3);
    que.push(4);
    que.push(5);
    que.push(6);
    que.push(7);
    que.push(8);
    que.push(9);
    for(ll i=0;i<K;i++)
    {
        ll x=que.front();
        que.pop();
        if (i==K-1)cout<<x;
        if(x%10!=0)que.push(10*x+x%10-1);
        que.push(10*x+x%10);
        if(x%10!=9)que.push(10*x+x%10+1);
    }
}