//Never stop chasing!-MdSourav.
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>

#define YES            cout<<"YES"<<endl;
#define NO             cout<<"NO"<<endl;
#define sz(x)          x.size()
#define ll             long long int
#define ls             long int
#define start          ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define test           int t;cin>>t;while(t--)
#define f(i, a, n)     for(int i=a; i<n;i++)
#define gcd(a,b)       __gcd(a,b)
#define lcd(a,b)       (a*b)/gcd(a,b)
#define pb             push_back
#define mp(x,y)        make_pair(x,y)
#define rsrt(v)        sort(v.begin(),v.end(),greater<int>());
#define srt(v)         sort(v.begin(),v.end())
#define basrt(a,n)     sort(a,a+n,greater<int>());
#define asrt(a,n)      sort(a,a+n)
#define fact(n)        ll x=1;for(ll i=1;i<=n;i++){x=(x*i);}
#define F              first
#define S              second
#define enter(v,n)     for(ll i=0;i<n;i++){ll x;cin>>x;v.pb(x);}
#define INF 	       1000000007
#define unique(v)      v.erase(unique(v.begin(),v.end()),v.end())
using namespace std;

double pi=3.14159265358979323846;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
    ll a,b,c;
    cin >> a >> b >> c;
     int x=a-b;
     int x2=c-x;
     if(x2<=0)
     {
         cout << "0" << endl;
     }
     else
     cout << x2 << endl;

	return 0;
}