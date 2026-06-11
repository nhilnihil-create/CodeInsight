#include<bits/stdc++.h>
// #include <ext/pb_ds/tree_policy.hpp>
// #include <ext/pb_ds/assoc_container.hpp>
#include<chrono>
using namespace std;
using namespace std::chrono;
//using namespace __gnu_pbds;
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
#define mod         1000000007
#define forf(i,a,b) for(int i=a;i<b;i++)
#define it(x)      x::iterator
#define ll         long long
#define debug(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
#define time__(d)  for(long blockTime = 0; (blockTime == 0 ? (blockTime=clock()) != 0 : false); debug("%s time : %.4fs", d, (double)(clock() - blockTime) / CLOCKS_PER_SEC))
#define vii        vector<int>
#define big        3e18
#define sm         -2e9
#define mkr        make_pair
#define vpi        vector<pair<int,int> >
#define pii        pair<int,int>
#define rng        500005
#define sz(x)      (int)x.size()
#define rv(x)      reverse(x.begin(),x.end())
#define out(x)     cout<<x.fi<<" "<<x.se<<endl;
 
//#define ordered_set tree<pii, null_type,less<pii>, rb_tree_tag,tree_order_statistics_node_update>
 
void pr_init()
{
 
#ifndef ONLINE_JUDGE
  freopen("gin.txt", "r", stdin);
  //freopen("gout.txt", "w", stdout);
#endif
}

void solve()
{
  
 //  int n,k;
 //  cin >> n >> k;
  
 //  map<int,int>mp;

 //  forf(i,1,n+1) cin >> a[i];
  
 //  int cn = 0 , s=0;
 // // mp[-1]=1;
 //  forf(i,1,n+1)
 //  {
 //    if((a[i])%k==1) cn++;
 //    int v == s+a[i]
 //    cn += mp[(s+a[i]-i-1+k)%k];
 //    cout<<cn<<"\n";
 //    mp[(s-i+k)%k]++;
 //    s+=a[i];
 //  }
 //  cout<<cn;
 
 int n,m;
 cin >> n >> m;
 string s;
 cin >> s;
 vector<int>sq;
 for(int i=0;i<sz(s);i++)
 {
   if(s[i]=='0')sq.pb(i);
 }
 if(s[0]=='1'||s[n]=='1')
 {
  cout<<"-1\n";
  return ;
 }

 int c = n,is=1;
 vii mv;

 while(c!=0)
 {
   mv.pb(c);
   auto it = lower_bound(sq.begin(),sq.end(),c-m);
  
   if(*it==c)
   {
    //cout<<"helln";
     is=0;
     break;
   }
   c = *it;
 }
 if(!is)
 {
  cout<<"-1";
  return ;
 }
 mv.pb(0);
 rv(mv);

 vii an;

 for(int i=1;i<sz(mv);i++)
 {
   an.pb(mv[i]-mv[i-1]);
 }
 // for(auto x:mv) cout<<x<<" ";
 //  cout<<"\n";
 for(auto x:an)
 {
  cout<<x<<" ";
 }
}
 
 
int32_t main()
{
  pr_init();
  fastio;
   
  
  solve();
   
}
 
