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

    int prev;
    int a[n];
    ll k;
    for(int i=0;i<n;i++)
    {
        cin>>k;
        if(i==0)
            a[i]=-1;
        else
        {
            if(prev>=k)
                a[i]=1;
            else
                a[i]=-1;
        }
        prev=k;
    }
    int maxsum=0,sum=0;
    for(int i=0;i<n;i++)
    {
        if(a[i]==1)
           sum+=a[i];
        else
            sum=0;
        maxsum=max(sum,maxsum);
    }
    cout<<maxsum<<"\n";
   return 0;
}
