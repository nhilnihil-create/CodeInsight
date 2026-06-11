#include<bits/stdc++.h>
#define ll long long
#define rep(i, n) for (ll i = 0; i < n; i++)
#define repr(i, a, b) for (ll i =a; i < b; i++)
#define all(a) a.begin(), a.end()
#define w(tc) ll tc;cin>>tc;while(tc--)
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);
#define PI 3.14159265359
static const int INF = 1e9 + 7;
using namespace std;

int main()
{
  int n;
  cin >> n;
  ll i = 2;
  ll ans = 0 ;
  for ( i = 1; i < 1000000; i++)
  {
    ans = (int)(ans*10+7) % n;
    if (ans == 0)
{      cout<<i<<endl;
       return 0;}
    
  }
  cout<<-1<<endl;
}

