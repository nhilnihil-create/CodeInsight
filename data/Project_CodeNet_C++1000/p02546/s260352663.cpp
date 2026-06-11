#include <bits/stdc++.h>
using namespace std;



#define INF (int)1e9
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
#define endl "\n"

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<string, string> pss;
typedef map<int, int> mii;

void solve(ll test_case)
{
  string s;
  cin>>s;
  if(s[s.size()-1] =='s' )
        s+="es";
  else{
        //if()
        s+="s";
    }
  cout<<s;
}

int main()
{

//#ifndef ONLINE_JUDGE
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
//#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t=1, t1 = 0;
  //  cin >> t;
    while (t1 < t)
    {
        solve(t1 + 1);
        t1++;
    }
 return 0;
}
