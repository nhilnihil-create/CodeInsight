#include <iostream>
#include <bits/stdc++.h>
#define ll long long

using namespace std;
ll a[100100],NextGreater[100100],LastGreater[100100],Log[2001000]
,SparseMax[400100][20],n;
stack < ll > S;

void BuildMax()
{
    for(ll j=1; j<=18; j++)
        for(ll i=1; i<=400000; i++)  SparseMax[i][j] = -1e18;
    for(ll i=1; i<=n; i++)  SparseMax[i][0] = a[i];
    for(ll j=1; j<=18; j++)
    {
        for(ll i=1; i<=n; i++)
        {
            SparseMax[i][j] = max(SparseMax[i][j-1], SparseMax[i + (1 << (j - 1))][j-1]);
        }
    }
}


void BuildLog()
{

    Log[1] = 0;
    for(ll i=2; i<=n; i++)  Log[i] = Log[i/2] + 1;
}

long long QueryMax(ll l, ll r)
{
    ll j = Log[r - l + 1];
    return max(SparseMax[l][j], SparseMax[r - (1 << j) +1][j]);
}

int main()
{
    cin >> n;
    for(ll i = 1; i<=n; i++)  cin >> a[i];
    for(ll i=1; i<=n; i++)
    {
        while(!S.empty() && a[S.top()]<a[i])
            NextGreater[S.top()] = i, S.pop();
        S.push(i);
    }
    while(!S.empty())  NextGreater[S.top()]=n+1,S.pop();
    NextGreater[n + 1] = n + 1;
    for(ll i=n; i>=1; i--)
    {
        while(!S.empty() && a[S.top()]<a[i])
            LastGreater[S.top()] = i, S.pop();
        S.push(i);
    }
    while(!S.empty())  LastGreater[S.top()]=0,S.pop();
    LastGreater[0] = 0;
    BuildLog();
    BuildMax();
    long long Ans = 0;
    for(ll i = 1; i<=n; i++)
    {
        ll L = LastGreater[i];
        ll R = NextGreater[i];
        ll Start = 1, End = L - 1, LeftSide = 0;
        while(Start <= End)
        {
            ll mid = (Start + End)/2;
            if(QueryMax(mid, L - 1) > a[i])  LeftSide = mid, Start = mid + 1;
            else  End = mid - 1;
        }
        Start = R + 1,End = n;
        ll RightSide = n + 1;
        while(Start <= End)
        {
            ll mid = (Start + End)/2;
            if(QueryMax(R + 1, mid) > a[i])  RightSide = mid, End = mid - 1;
            else  Start = mid + 1;
        }
        L = LastGreater[i] - LeftSide;
        R = NextGreater[i] - i;
        Ans+=a[i] * (R * L);
        L = i - LastGreater[i];
        R = RightSide - NextGreater[i];
        Ans+=a[i] * (R * L);
    }
    cout << Ans;
    return 0;
}
