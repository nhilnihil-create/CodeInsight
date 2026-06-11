/*
Miles Morales : When will I know I'm ready?
Peter B. Parker : You won't. It's a leap of faith. That's all it is, Miles. A leap of faith.
*/
//KEEP IT SIMPLE STUPID
#include<string>
#include<bits/stdc++.h>


#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define fore(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)
#define print(v) for(auto it=(v).begin();it!=(v).end();it++) {cout<<*it<<" ";}
#define ll long long
#define w(t) ll t;cin>>t;while(t--)

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef long long i64;
typedef vector<i64> vi64;
typedef vector<vi64> vvi64;
using namespace std;


int main()
{
    int n,k,ans=0;
  cin>>n>>k;
  while(n--)
  {
    int h;
    cin>>h;
    ans+=(h>=k);
  }
  cout<<ans<<"\n";
    return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/
