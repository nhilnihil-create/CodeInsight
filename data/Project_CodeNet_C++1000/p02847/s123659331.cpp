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
  
    map<string,int>mp;
    mp["SUN"]=7;
    mp["MON"]=1;
    mp["TUE"]=2;
    mp["WED"]=3;
    mp["THU"]=4;
    mp["FRI"]=5;
    mp["SAT"]=6; 
    
    string s;
    cin >> s;

    int k = mp["SUN"] -  mp[s];
    if(k==0) cout<<"7";
    else cout<<k;
}
 
 
int32_t main()
{
  pr_init();
  fastio;
   
  
  solve();
   
}
 
