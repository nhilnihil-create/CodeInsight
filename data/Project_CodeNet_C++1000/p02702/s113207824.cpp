 #include<bits/stdc++.h>
 #include <ext/pb_ds/tree_policy.hpp>
 #include <ext/pb_ds/assoc_container.hpp>
 #include<chrono>
 using namespace std;
 using namespace std::chrono;      
 using namespace __gnu_pbds; 
 #define fastio     ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
 #define fi         first
 #define se         second
#define int         long long 
 #define pb         push_back
 #define emp        emplace_back
 #define vv(x)      vector<x>
 #define mp(x,y)    map<x,y>
 #define dq(x)      deque<x>
 #define pql(x)     priority_queue<x>
 #define pqs(x)     priority_queue<x,vv(x),greater<x> >
 #define M          1000000007
 #define forf(i,a,b) for(int i=a;i<b;i++)
 #define it(x)      x::iterator
 #define ll         long long 
 #define debug(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
 #define time__(d)  for(long blockTime = 0; (blockTime == 0 ? (blockTime=clock()) != 0 : false); debug("%s time : %.4fs", d, (double)(clock() - blockTime) / CLOCKS_PER_SEC))
 #define vii        vector<int>
 #define big        2e18
 #define sm         -1e9
 #define mkr        make_pair
 #define vpi        vector<pair<int,int> >
 #define pii        pair<int,int>
 #define rng        500005
 #define sz(x)      (int)x.size()
 #define rv(x)      reverse(x.begin(),x.end())
 #define out(x)     cout<<x.fi<<" "<<x.se<<endl;

#define ordered_set tree<pii, null_type,less<pii>, rb_tree_tag,tree_order_statistics_node_update> 
  
void pr_init()
{
   
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
   
    #endif
}



int dp[200001];

int rs(int a,int b,int m)
{
  int an=1;
  while(b>0)
  {
    if(b%2!=0) an = (a%m*an%m)%m;
    b/=2;
    a = (a%m *a%m)%m;
  }
  return an;
}

void solve()
{
 
string s;
cin >> s;

int n = sz(s),vl=2019;

for(int j=n-1;j>=0;j--)
{
  int bs = rs(10,n-1-j,vl);

  dp[j] = dp[j+1]+ ((s[j]-'0')%vl*bs%vl)%vl;
  dp[j]%=vl;
}

int an=0;
map<int,int>mp;
mp[0]=1;
for(int j=n-1;j>=0;j--)
{
  an+=mp[dp[j]];
  mp[dp[j]]++;
}
// forf(j,0,n) cout<<dp[j]<<" ";
// cout<<endl;
cout<<an<<endl;
}

int32_t main()
{
  pr_init();
  fastio;
  
  auto start = high_resolution_clock::now(); 
 
  solve();
  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop - start); 
  
    // cout << "Time taken by function: "
    //      << duration.count() << " microseconds" << endl; 

 }
