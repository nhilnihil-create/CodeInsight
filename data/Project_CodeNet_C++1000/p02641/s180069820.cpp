/**-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
*-*                                                               *-*
*-*                  Bismillahir Rahmanir Rahim                   *-*
*-*                                                               *-*
*-*                  Author: Ahsan Habib (comrade)                *-*
*-*                    Metropolitan University                    *-*
*-*                         Language: C++                         *-*
*-*                                                               *-*
*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-**/
#include<bits/stdc++.h>
#include<istream>
#include<cstdio>
#define pii          pair<ll,ll >
#include<string>
#define In freopen("ahsan.txt","r",stdin);
#define ll long long
#define ff first
#define ss second
#define NO cout<<"NO"<<endl
#define m1 cout<<"-1"<<endl
#define No cout<<"No"<<endl
#define cinarr0(n) for(int i = 0;i<n;i++)cin>>a[i];
#define cinarr1(n) for(int i = 1;i<=n;i++)cin>>a[i];
#define YES cout<<"YES"<<endl
#define Yes cout<<"Yes"<<endl
#define pb push_back
#define sorta(a) sort(a,a+n)
#define sortv(v)  sort(v.begin,v.end())
#define bug(a) cerr << #a << " : " << a << endl
#define all(v) (v.begin(), v.end())
#define   sz(x)       x.size()
#define fill(x, y) memset(x, y, sizeof(x))
const int mx = 1e6+5;
using namespace std;
ll a[200050],m,ans,i,t,k,ev=0,od=0,tt=0,cas = 1;
ll dp[200050];
bool ok = true;
int main()
{

    //In;
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<ll>v(200);
    ll n,x,pos;
    cin>>x>>n;
    map<int,int>mp;
    for(ll i = 0; i<n; i++)
    {
        cin>>v[i];
        mp[v[i]]++;
    }
    sort(v.begin(),v.end());
    int tm = x,n1 = 0 ,n2 = 0;
    while(tm--)
    {
        if(mp[tm]==0)
        {
            n1 = tm;
            break;
        }

    }
    tm = x;
    while(tm<v.size())
    {
        if(mp[tm]==0)
        {
            n2 = tm;
            break;
        }
        tm++;
    }

    if(x-n1==n2-x)
    {
        cout<<min(n1,n2)<<endl;
    }
    else if(x-n1>n2-x)cout<<n2<<endl;
    else cout<<n1<<endl;
    return 0;
}
