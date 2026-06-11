//#include<bits/stdc++.h>
#include<iostream>
//#include<vector>
//#include<map>
//#include <iomanip>
//#include<cstring>
//#include<string>
//#include<cmath>
#include<stack>
#include<queue>
#include<algorithm>
#define ll long long
#define eps 1e-9
#define endl "\n"
#define PI acos(-1)
#define pb push_back
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL)
#define rep(j,n) for(int j=0;j<n;j++)
using namespace std;
/*
ll mod=1e9+7;
bool f(const pair<ll,ll>&a,const pair<ll,ll>&b)
{
    return (a.first<b.first);
}
bool f2(const pair<ll,ll>&a,const pair<ll,ll>&b)
{
    return (a.second<b.second);
} */

int main()
{
    fast;
    string s;
    cin>>s;
    int r=0;
    int maxi=0;
    int res=0;
    for(int i=0; i<s.length(); i++)
    {
        int ct=0;
        if(s[i]=='R')
        {

            for(int j=i; j<s.length(); j++)
            {
                if(s[j]!='R')
                {
                    break;
                }
                ct++;
            }
            maxi=max(maxi,ct);
        }
    }
    cout<<maxi<<endl;


    return 0;
}
