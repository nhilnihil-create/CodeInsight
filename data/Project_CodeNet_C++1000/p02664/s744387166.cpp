#include<bits/stdc++.h>
#define u64 uint64_t
#define ll long long
#define endl "\n"
#define pi acos(-1)
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
int main()
{
    fast
    ll n,m,x,y,i,j,k,p,f=0,tc,cnt=0,sum=0,pro=1,mi=1e18,ma=-1e18;
    string str;
    char ch;
    double db;
    deque<ll>dq;
    map<ll,ll>mp;
    set<ll>st;
    vector<ll>vt;
    //code
    cin>>str;
    for(i=0;i<str.size();i++)
    {
        if(str[i]=='?')
        {
            str[i]='D';
        }
    }
    cout<<str<<endl;




    //code
    return 0;
}
