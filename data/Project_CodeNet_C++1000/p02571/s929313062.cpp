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
ll a[200010],m,ans,i,t,k,ev=0,od=0,tt=0,n,cas = 1;
vector<int>vec[mx];
int ar[10000][10000];
vector<pii>v;
bool ok = true;
int main()
{

    // In;
    //ios::sync_with_stdio(false);
    //  cin.tie(0);
    string s1,s2;
    cin>>s1>>s2;
    int ans = 0;
    for(int i = 0 ; i <=s1.size() - s2.size(); i++)
    {
        int cnt = 0;
        for(int j = 0; j<s2.size(); j++)
        {
            if(s1[j+i]==s2[j])cnt++;
        }
        ans = max(ans,cnt);
    }
    cout<< s2.size() - ans<<endl;

    return 0;
}
