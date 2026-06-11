#include<bits/stdc++.h>
#define lld long long int
#define pb push_back
#define in insert
#define mod 1000000007
#define pi 3.14159265358979

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    lld n,x;
    cin>>n;
    map<lld,lld>m;

    for(lld i=0;i<n;i++)
    {
        cin>>x;
        m.in({x,i+1});
    }
    for(auto it=m.begin();it!=m.end();it++)
    {
        cout<<it->second<<' ';
    }
    cout<<"\n";
}
