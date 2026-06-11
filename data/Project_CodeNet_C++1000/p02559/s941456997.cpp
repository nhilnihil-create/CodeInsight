/*
    Auther: ghoshashis545 Ashis Ghosh
    College: Jalpaiguri Govt Enggineering College
*/
#include<bits/stdc++.h>
#include<string>
#include<algorithm>
using namespace std;
#define ll int
#define int long long
#define ld long double
#define ff first
#define ss string 
#define se second
#define endl "\n"
#define alt(v) v.begin(),v.end()
#define ralt(v) v.rbegin(),v.rend()
#define pb emplace_back
#define mp make_pair
#define debug(x) cerr << #x << " : " << x << '\n'
#define fab(i,a,b) for(int i=(a);i<(b);i++)
#define fba(i,a,b) for(int i=(b);i>=(a);i--)
int mod=1000000007;
// int mod=998244353;
int dx[]={-1,1,0,0,-1,-1,1,1};
int dy[]={0,0,1,-1,1,-1,1,-1};

bool test  = 0;

const int inf = 1e18;
const int N = 1e6 + 5;


int bit[N];

void update(int idx, int val)
{
  while(idx <= N)
  {
    bit[idx] += val;
    idx += idx & -idx;
  }
}

void updateMax(int idx, int val)
{
  while(idx <= N)
  {
    bit[idx] = max(bit[idx], val);
    idx += idx & -idx;
  }
}

int pref(int idx)
{
  int ans = 0;
  while(idx > 0)
  {
    ans += bit[idx];
    idx -= idx & -idx;
  }
  return ans;
}

int rsum(int l, int r)
{
  return pref(r) - pref(l - 1);
}

int prefMax(int idx)
{
  int ans = -2e9;
  while(idx > 0)
  {
    ans = max(ans, bit[idx]);
    idx -= idx & -idx;
  }
  return ans;
}



void solve()
{
    
  int n,q,x,ind,l,r;
  cin>>n>>q;
  int arr[n];
  for(int i = 1; i <= n; i++)
  {
    cin >> arr[i-1];
    update(i,arr[i-1]);
  }
 
  for(int i=0;i<q;i++)
  {
     int t1;
     cin>>t1;
     if(t1==0)  
     {
        cin>>ind>>x;
        ind+=1;
        update(ind,x);
     }
     else{
      cin>>l>>r;
      l+=1;
      cout<<rsum(l,r)<<"\n";
     }
  }

}




    

















signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    // precompute();
    int t=1;
    if(test)
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}