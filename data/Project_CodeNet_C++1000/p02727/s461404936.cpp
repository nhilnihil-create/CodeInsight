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
 #define mod        1000000007
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


int p[100001],q[100001],r[100001];
void solve()
{
 
int x,y,a,b,c;
cin >> x >> y >> a >> b >> c;

forf(i,0,a) cin >> p[i];
forf(i,0,b) cin >> q[i];
forf(i,0,c) cin >> r[i];

sort(p,p+a,greater<int>());
sort(q,q+b,greater<int>());
sort(r,r+c,greater<int>());

int i=x-1,j=y-1,k=0;

int sw=0;


for(int l=0;l<x+y;l++)
{
    if(i<0)
    {
        if(k<c && q[j] < r[k])
        {
            swap(q[j],r[k]);
            k++;
           
        }
        j--;
    }
    else if(j<0)
    {
        if(k<c && p[i] < r[k])
        {
            swap(p[i] , r[k]);
            k++;
        }
        i--;
    }
    else
    {
        if(p[i] < q[j])
        {
            if(k<c && p[i] < r[k])
        {
            swap(p[i] , r[k]);
            k++;
        }
        i--;
          
        }else
        {
        if(k<c && q[j] < r[k])
        {
            swap(q[j],r[k]);
            k++;
           
        }
        j--;

        }
    }
}


forf(i,0,x) sw+=p[i];
forf(i,0,y) sw+=q[i];


cout<<sw<<endl;

}

int32_t main()
{
  //pr_init();
  //fastio;
  
  auto start = high_resolution_clock::now(); 
 
  solve();
  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop - start); 
  
    // cout << "Time taken by function: "
    //      << duration.count() << " microseconds" << endl; 

 }
