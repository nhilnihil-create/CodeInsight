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

main()
{
    int m,d; cin>>m>>d;
    int cnt=0;

    rep2(i,1,m+1)rep2(j,1,d+1)
    {
        if(j<21)continue;
        int d1=j%10,d10=j/10;
        if(d1*d10==i)
        {
            if(d1>=2)cnt++;
        }
    }
    cout<<cnt<<endl;

}