#include<bits/stdc++.h>
using namespace std;

#define M1 1000000007
#define M2 1000000009
#define ll long long 
#define ull unsigned long long
#define ui unsigned int
#define us unsigned short
#define INF 1001001001
#define PI 3.1415926535897932384626
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define f0(i, n) for (int i = 0; i < (int)(n); ++i)
#define f1(i, n) for (int i = 1; i <= (int)(n); ++i)
#define fc0(i,l,r) for(int i = (int)(l); i<(int)(r); ++i)
#define fc1(i, l, r) for (int i = (int)(l); i <= (int)(r); ++i)
#define fr0(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define all(x) (x).begin(), (x).end()
#define sz(a) int((a).size())
#define tr(c,i) for(typeof((c)).begin() i = (c).begin(); i != (c).end(); i++)
typedef vector<int> vi; 
typedef vector<vi> vvi; 
typedef pair<int,int> ii; 
 
void init()
{
  #ifndef ONLINE_JUDGE
      freopen("input.txt", "r", stdin);
      freopen("output.txt", "w", stdout);
      freopen("error.txt", "w", stderr);
    #endif

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    cout << fixed;
}

signed main()
{
    init();

    int n,c=0;
    cin>>n;
    string s;
    cin>>s;
    if(n%2!=0)
    {
      cout<<"No"<<endl;
    }
    else
    {
      f0(i,n/2){if(s[i]==s[i+n/2]){c++;}}
      if(c==n/2){cout<<"Yes"<<endl;}
      else
        cout<<"No"<<endl;
    }

    cerr<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl;
    return 0;
}