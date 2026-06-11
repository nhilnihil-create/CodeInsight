#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <set>
#define ll long long
#define rep(i, a, b) for (int i = int(a); i <= int(b); i++)
#define sz(a) int((a).size())
#define shit while(t--)
#define fr for(int i=0;i<n;i++)
int maxo=1e9+7;
using namespace std;
int arr[95];
ll dp[20001];
const int mod= 1e9+7;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n,x;
    string s;
    cin>>n>>s;
    if(n%2==0)
    {
        string a="";
        string b="";
        for(int i=0; i<n/2; i++)
        {
            a+=s[i];
        }
        for(int j=n/2; j<n; j++)
        {
            b+=s[j];
        }
        if(a==b)
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }
    else
    {
        cout<<"No"<<endl;
    }
    return 0;
}
