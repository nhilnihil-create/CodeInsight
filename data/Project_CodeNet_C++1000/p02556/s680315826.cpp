#include<bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
using namespace std;
#define ll long long
#define ff first
#define ss second
#define pb push_back
#define deb(x) cout<<x<<"\n";
#define deB(x,y) cout<<x<<" "<<y<<"\n";
#define Deb(x,y,z) cout<<x<<" "<<y<<" "<<z<<"\n";
#define YES cout<<"YES\n";
#define Yes cout<<"Yes\n";
#define NO cout<<"NO\n";
#define No cout<<"No\n";
#define clt(x) 63-__builtin_clzll(x)
#define bct(x) __builtin_popcountll(x)
#define all(v) (v).begin(),(v).end()
#define pi pair<ll,ll>
#define vi vector<ll>
#define vpi vector<pair<ll,ll>>
#define maxq priority_queue<ll>
#define minq priority_queue<ll,vector<ll>, greater<ll>>
#define cont continue;
#define reto return 0;
#define sz size()
#define spmod 1116295198451
#define mod 1000000007
#define md 998244353 
#define N 2e5+10
//typedef tree<int,null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update> //pbds;

bool cmp(pi a,pi q)
{
  return a.ff+a.ss<q.ff+q.ss;
}
bool qwe(pi a,pi q)
{
  return a.ff-a.ss<q.ff-q.ss;
}
bool wer(pi a,pi q)
{
  return a.ss-a.ff<q.ss-q.ff;
}
int main()
{
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  //freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
  ll n;
  cin>>n;
  vpi a(n);
  for(auto &x:a)
    cin>>x.ff>>x.ss;
  sort(all(a),cmp);
  ll ans=a[n-1].ff+a[n-1].ss-a[0].ff-a[0].ss;
  sort(all(a),qwe);
  ans=max(ans,a[n-1].ff-a[n-1].ss-a[0].ff+a[0].ss);
  sort(all(a),wer);
  ans=max(ans,-a[n-1].ff+a[n-1].ss+a[0].ff-a[0].ss);
  deb(ans)
}