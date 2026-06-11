#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
#define FAST std::ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pi       acos(-1)
#define mp make_pair
#define pb push_back
#define ALL(v) v.begin(), v.end()
#define SORT(v) sort(ALL(v))  
#define REVERSE(v) reverse(ALL(v))
#define F first
#define S second
#define ppb pop_back
#define GCD(m,n) __gcd(m,n)
#define LCM(m,n) (m*n)/GCD(m,n)
#define inputarr(a,n) for(int i=0;i<n;++i) cin>>a[i]
#define initarr(a,n,x) for (int i=0;i<n;++i) a[i]=x
#define rep(i,a,n)  for(int i=a ; i<n ; i++)
#define repe(i,a,n) for(int i=a;i<=n;i++)
#define rev(i,a,b) for(int i=a;i>=b;i--)

// #define int long long ////////////
#define MOD 1000000007    ////////
#define POD 998244353 ////////
//define ll long long
#define ld long double 

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<vvvi> vvvvi;
typedef vector<char> vc;
typedef vector<vc> vvc;
typedef vector<vvc> vvvc;
typedef vector<pii > vpii;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef map<int,int> mii;
typedef unordered_map<int,int> umii;
typedef map<char,int> mci;

#define itv for(auto it= v.begin(); it != v.end(); ++it )
#define present(container, element) (container.find(element) != container.end())
#define cpresent(container, element) (find(ALL(container),element) != container.end())
//#define invect(data,n,commands) for(int i = 0;i<n;i++){int tmp;cin>>tmp;data.pb(tmp);commands}
//#define inset(data,n,commands) for(int i = 0;i<n;i++){int tmp;cin>>tmp;data.insert(tmp);commands}
//#define trav(a, x) for(auto& a : x)
//#define display(x) trav(a,x) cout<<a<<" ";cout<<endl
 
 
#define bs binary_search
#define  lb(v,val)  lower_bound(ALL(v), val)
#define  ub(v,val)  upper_bound(ALL(v), val)
#define Max(x,y,z) max(x,max(y,z))
#define Min(x,y,z) min(x,min(y,z))
#define maxc(v) *max_element(ALL(v))
#define minc(v) *min_element(ALL(v))
 /*
#define dbg1(a) cout<<" *"<<a<<" ";
#define dbg2(a,b) cout<<" *"<<a<<" **"<<b<<" "     /////
#define dbg cout<<"move"
*/

#define vin(v,n);   vi v(n); rep(i,0,n)  cin>>v[i];
#define dbg cerr <<"At line "<<__LINE__<<" move "<<nl
#define dbg1(x) cerr <<"At line "<<__LINE__<<" "<<#x<<"="<<x<<nl
#define dbg2(x,y) cerr <<"At line "<<__LINE__<<" "<<#x<<"="<<x<<" "<<#y<<"="<<y<<nl
#define dbg3(x,y,z) cerr <<"At line "<<__LINE__<<" "<<#x<<"="<<x<<" "<<#y<<"="<<y<<" "<<#z<<"="<<z<<nl
#define prv(v);     rep(i,0,sz(v))  cerr<<v[i]<<" ";
#define nl "\n"
#define sz(s)         (int)((s).size())
#define coutsp(k)   cout<<setprecision(k)  //set precision (total length k icluding decimal and non decimal)
#define coutfsp(k)   cout<<fixed<<setprecision(k)  //fixed set precision(after decimal fixing)

#define isvowel(a) (a=='a'||a=='e'||a=='i'||a=='o'||a=='u')
#define  INF   (int)2e9


//------------------------ Global VARIABLE ------------------------------------

const int N=12;
const int M=1000;

int n,m;

int a[M+1];
vi C[M+1];

// unordered_map<pair<int,int>,pii> dpm;

int dpm[M+1][4100];
// int valid[M+1][2050]={};

int tru=1;


//------------------------ Global VARIABLE ------------------------------------
string N2B(int no)
{
  string s="";
  while(no!=0)
  {
    if(no&1)
      s+='1';
    else
      s+='0';
    no=no>>1;  
  }

  while(sz(s)!=n)
    s+='0';

  REVERSE(s);  
  return s;
}

int B2N(string s, int m)
{
  rep(i,0,sz(C[m]))
    s[C[m][i]-1]='1';

  REVERSE(s);

  int p=1;

  int no=0;
   
   rep(i,0,sz(s))
   {
    if(s[i]=='1')
      no+=p;
    p*=2;
   }

   return no;

}
//-------------------------------------------------------------------
int recurso(int n1 , int vis )
{


  if(dpm[n1][vis]!=-1)
  return dpm[n1][vis];
 

  if(vis==tru)  return dpm[n1][vis] = 0;

  if(n1<=0)  return dpm[n1][vis] = INF; 


  // dbg2(n1,vis);

  int ans=INF,check=0;

  int d=recurso(n1-1,vis);

  if(d!=INF)
    ans=min(ans,d);
   
  
 int vis1=B2N(N2B(vis),n1);

  d=recurso(n1-1,vis1);
  if(d!=INF)
  ans=min(ans,d+a[n1]);

  return dpm[n1][vis]= ans;

}
//-------------------------------------------------------------------------------

void dquit()
{  
   cin>>n>>m;

   memset(dpm,-1,sizeof(dpm));

   rep(i,1,m+1)
   {

    int b;  cin>>a[i]>>b;

    rep(j,0,b)  {int c; cin>>c; C[i].pb(c); }

   }
  
   rep(i,0,n)
    tru*=2;
    tru--;

  int ans=recurso(m,0);

  if(ans==INF)  cout<<-1;
  else
  {
    cout<<ans;
  }


}
//-------------------------------------------------------------------------------

 
signed main()
{

   
//--------------------------------
     FAST    // MAKE IT FAST   ---
//--------------------------------

/////////////////////////////////////////////////////////////////////////////////////////// 

/////////////////////////////////////////////////////////////////////////////////////////// 
   
   int t;  t=1;    
   int co=1;
///////---------------------------------|||||
               // cin>>t;        ////////>>>>>>>
//////----------------------------------|||||

    while(t--)
    {
       // cout<<"Case #"<<co<<": ";

      dquit();
      cout<<nl;   //  IMPORTANT FOR NEXT LINE     
      co++;  
    }


 // #ifndef ONLINE_JUDGE
 //  cerr<<(1000*clock())/CLOCKS_PER_SEC<<"ms";
 // #endif      

   return 0;
}