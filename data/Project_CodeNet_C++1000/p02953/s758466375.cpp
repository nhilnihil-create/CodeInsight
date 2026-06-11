/****************************************************************************************************
                                        SUBMITTED BY-

                                            AISH_07

****************************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define ll long long
#define sl set<ll>
#define vs vector<string>
#define pb push_back
#define vl vector<ll>
#define vi vector<int>
#define PI  3.14159265
#define mod 998244353
int main()
{
    int n;
    cin>>n;

    ll h[n];
    for(int i=0;i<n;i++)
        cin>>h[i];

    int flag=1;

    for(int i=1;i<n;i++)
    {
        if(h[i]==h[i-1])
            continue;
        else if(h[i]>h[i-1])
            h[i]--;
        else
        {
            flag=0;
            break;
        }
    }
    if(flag)
        cout<<"Yes\n";
    else
        cout<<"No\n";
    return 0;
}
