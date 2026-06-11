#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0)
#define ull unsigned ll
#define uint unsigned
#define pai pair<int,int>
#define pal pair<ll,ll>
#define IT iterator
#define pb push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);++i)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);--i)
#define endl '\n'
#define ll long long
int main()
{
    int flag=0;
    int a,b,c,k;
    int cnt=0;
    cin>>a>>b>>c>>k;
    while(1)
    {
        if(b>a)
        {
            flag=1;
             break;
        }

        b*=2;
        cnt++;
    }
    for(int i=0;i<k-cnt;i++)
    {
        c*=2;
    }
    if(flag==1)
    {
        if(c>b)
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }
    else
        cout<<"No"<<endl;
}
