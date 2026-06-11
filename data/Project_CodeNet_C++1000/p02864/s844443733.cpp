#include<bits/stdc++.h>
using namespace std;

#define ll long long

vector <long> arr;
int n,k;
ll dp[303][303][303];

long f(int prev, int cur, int ck);

int main()
{
    cin>>n>>k;
    arr.push_back(0);

    long tmp;

    for(int i=0; i<302; i++)
    {
        for(int j=0; j<302; j++)
        {
            for(int k=0; k<302; k++)
                dp[i][j][k] = -1;
        }
    }

    for(int i=0; i<n; i++)
    {
        cin>>tmp;
        arr.push_back(tmp);
    }

    long ans = f(0, 1, 0);
    cout<<ans;
    return 0;
}

long f(int prev, int cur, int ck)
{
    if(cur>n) return 0;
    if(dp[prev][cur][ck] != -1) return dp[prev][cur][ck];

    long val = max((long)0, arr[cur]-arr[prev] );
    ll l1 = f(cur, cur+1, ck) + val;
    ll l2 = ck<k ? f(prev, cur+1, ck+1): 1000000000000000;
    dp[prev][cur][ck] = min(l1, l2);

    return dp[prev][cur][ck];
}