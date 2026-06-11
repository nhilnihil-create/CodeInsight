/*Whose woods these are I think I know.
His house is in the village though;
He will not see me stopping here
To watch his woods fill up with snow.

My little horse must think it queer
To stop without a farmhouse near
Between the woods and frozen lake
The darkest evening of the year.

He gives his harness bells a shake
To ask if there is some mistake.
The only other sound’s the sweep
Of easy wind and downy flake.

The woods are lovely, dark and deep,
But I have promises to keep,
And miles to go before I sleep,
And miles to go before I sleep.*/

#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define pb push_back
#define fi first
#define se second
#define MOD 1000000007
const int maxn= 100010;
int l[2020][2020];
int r[2020][2020];
int u[2020][2020];
int d[2020][2020];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int h=0,w=0,res=0;
    cin>>h>>w;
    vector<string> v(h);
    for(int i=0;i<h;++i)
        cin>>v[i];
    for(int i=0;i<h;++i)
    {
        int curr=0;
        for(int j=0;j<w;++j)
        {
            if(v[i][j]=='#')
                curr=0;
            else
                ++curr;
            l[i][j]=curr;
        }
    }
    for(int i=0;i<h;++i)
    {
        int curr=0;
        for(int j=w-1;j>=0;--j)
        {
            if(v[i][j]=='#')
                curr=0;
            else
                ++curr;
            r[i][j]=curr;
        }
    }
    for(int j=0;j<w;++j)
    {
        int curr=0;
        for(int i=0;i<h;++i)
        {
            if(v[i][j]=='#')
                curr=0;
            else
                ++curr;
            u[i][j]=curr;
        }
    }
    for(int j=0;j<w;++j)
    {
        int curr=0;
        for(int i=h-1;i>=0;--i)
        {
            if(v[i][j]=='#')
                curr=0;
            else
                ++curr;
            d[i][j]=curr;
        }
    }
    for(int i=0;i<h;++i)
        for(int j=0;j<w;++j)
        {
            if(v[i][j]=='.')
                res=max(res,l[i][j]+r[i][j]+u[i][j]+d[i][j]-3);
        }
    cout<<res<<endl;
}