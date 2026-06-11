 #include<bits/stdc++.h>
 // #include <ext/pb_ds/tree_policy.hpp>
 // #include <ext/pb_ds/assoc_container.hpp>
 #include<chrono>
  using namespace std;
   using namespace std::chrono;      
  // using namespace __gnu_pbds; 
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
 #define big        1e18
 #define sm         -2e18
 #define mkr        make_pair
 #define vpi        vector<pair<int,int> >
 #define pii        pair<int,int>
 #define rng        500005
 #define sz(x)      (int)x.size()
 #define rv(x)      reverse(x.begin(),x.end())
 #define out(x)     cout<<x.fi<<" "<<x.se<<endl;
#define MEM(x,val) memset(x,val,sizeof(x))

 // typedef tree<pii, null_type, less<pii>, rb_tree_tag,  
 //            tree_order_statistics_node_update>  odst; 


void pr_init()
{
   
    #ifndef ONLINE_JUDGE
    freopen("gin.txt", "r", stdin);
   // freopen("output.txt", "w", stdout);
   
    #endif
}


const int Mxn = 1e6+1;
int mp[Mxn] , prim[Mxn] , ar[Mxn];

void solve()
{
  
  int n;
  cin >> n;
  
  int GCD = 0;
  forf(i,0,n) 
  {
    cin >> ar[i];
    if(GCD == 0 ) GCD = ar[i];
    else GCD = __gcd(GCD,ar[i]);
  }
  

  forf(i,0,n)
  {
    mp[ar[i]]++;
  }
  
  int is = 0;

  for(int i=2;i<Mxn;i++)
  if(prim[i]==0)
  {
      int c = 0;
      for(int j=1;j*i<Mxn;j++)
      {
        c+=mp[i*j];
        prim[i*j]=1;
      }
      if(c>1)
      {
        is=1;
        break;
      }
  }
  
  if(GCD != 1)
  {
    cout<<"not coprime";
    return ;
  }
  if(is==0)
  {
    cout<<"pairwise coprime";
    return ;
  }
  
  cout<<"setwise coprime";


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

  return 0;
}