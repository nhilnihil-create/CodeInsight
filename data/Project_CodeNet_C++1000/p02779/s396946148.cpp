//#include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<map>
#include <iomanip>
//#include<cstring>
//#include<string>
#include<cmath>
#include<queue>
//#include<stack>
#include<algorithm>
#define ll long long
#define eps 1e-9
#define endl "\n"
#define PI acos(-1)
#define pb push_back
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL)
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
int main()
{
    fast;
    map<int,int>m;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int num;
        cin>>num;
        m[num]++;
    }
    int f=0;
    for(auto it=m.begin();it!=m.end();it++)
    {
        if(it->second>1)
        {
            f=1;

            break;
        }
    }
    if(f==1)
    {
        cout<<"NO"<<endl;
    }
    else
    {
        cout<<"YES"<<endl;
    }


    return 0;
}
