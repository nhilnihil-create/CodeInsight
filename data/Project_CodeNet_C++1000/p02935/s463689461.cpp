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
    double a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    sort(a,a+n);

    double res=(a[0]+a[1])/2.0;

    for(int i=2;i<n;i++)
    {
        res+=a[i];
        res/=2.0;
    }
    cout<<res<<"\n";
   return 0;
}
