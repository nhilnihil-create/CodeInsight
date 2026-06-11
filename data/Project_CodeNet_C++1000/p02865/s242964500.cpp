#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep2(i,a,b) for(int i=a;i<b;i++)
#define each(it,v) for(auto it : v)
#define mod 1000000007
#define all(v) (v).begin(),(v).end()
#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define vpii vector<pair<int,int>>
#define vv vector<vector<int>>
using namespace std;

int n;

double d(int x1,int y1,int x2,int y2)
{
    return sqrt(pow(x1-x2,2)+pow(y1-y2,2));
}

int fact(int i)
{
    if(i==1)return 1;
    return i*fact(i-1);
}

main()
{
    cin>>n;

    if(n%2==0)
    {
        cout<<n/2-1<<endl;
    }else
    {
        cout<<n/2<<endl;
    }
}