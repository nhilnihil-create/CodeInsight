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
 #define M          998244353
 #define forf(i,a,b) for(int i=a;i<b;i++)
 #define it(x)      x::iterator
 #define ll         long long 
 #define debug(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
 #define time__(d)  for(long blockTime = 0; (blockTime == 0 ? (blockTime=clock()) != 0 : false); debug("%s time : %.4fs", d, (double)(clock() - blockTime) / CLOCKS_PER_SEC))
 #define vii        vector<int>
 #define big        1e18
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
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
   
    #endif
}

string s;

int nCrModpDP(int n, int r, int p) 
{ 
    int C[r+1]; 
    memset(C, 0, sizeof(C)); 
  
    C[0] = 1; // Top row of Pascal Triangle 
  
    for (int i = 1; i <= n; i++) 
    { 
        for (int j = min(i, r); j > 0; j--) 
  
            C[j] = (C[j] + C[j-1])%p; 
    } 
    return C[r]; 
} 
   
int nCrModpLucas(int n, int r, int p) 
{ 
   if (r==0) 
      return 1; 
   int ni = n%p, ri = r%p; 
  
   return (nCrModpLucas(n/p, r/p, p) * // Last digits of n and r 
           nCrModpDP(ni, ri, p)) % p;  // Remaining digits 
} 

bool ok()
{
  int pr = 0,n=sz(s);
  for(int i=0;i<sz(s);i++)
  {
    pr += (nCrModpLucas(n-1,i,2)*(s[i]-'0') )%2 ;
    
  }
  if(pr%2!=0) return 1;
  return 0;
}
void solve()
{
  
 int n;
 cin >> n ;
 cin >> s; 

 forf(i,0,sz(s))
 {
  s[i] = (int)(s[i]-'0')-1 + '0';
 } 
 
 
 if(ok())
 {
  cout<<"1\n";
  return;

 }
 
 int bl = 0;
 forf(i,0,n)
 {
  if(s[i] == '1') 
  {
    cout<<"0\n";
    return;
  }
  s[i] = (s[i]-'0')/2 + '0';
 }
 
if(ok())
{
  cout<<"2\n";
  return ;
} 

cout<<"0\n";

}

int32_t main()
{
  //pr_init();
  fastio;
  
  auto start = high_resolution_clock::now(); 
 
  solve();
  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop - start); 
  
    // cout << "Time taken by function: "
    //      << duration.count() << " microseconds" << endl; 

 }