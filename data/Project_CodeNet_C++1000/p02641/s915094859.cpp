#include <bits/stdc++.h>
using namespace std;
 
#define S size()
#define E end()
#define B begin()
#define L length()
 
#define endl "\n"
#define cnt count
#define in insert
#define er erase
#define fi first
#define se second
#define fl float
#define ld long double
#define ll long long

#define gcd __gcd
#define mp make_pair
#define pb push_back
#define popb pop_back()
#define pf push_front
#define popf pop_front()
#define all(v) v.B,v.E
#define acc(v) accumulate(all(v), 0)
#define psum partial_sum
#define lb lower_bound
#define ub upper_bound
#define bs binary_search
#define np next_permutation
#define maxe *max_element
#define mine *min_element
 
#define forl(i,n) for(ll i = 0; i < n; i++)
#define fore(i,m,n) for (ll i = m; i <= n; i++)
#define rforl(i,n) for (ll i = n - 1; i >= 0; i--)
#define rfore(i,m,n) for (ll i = m; i >= n; i--)    
#define iter(s) for(auto it:s)
 

#define prec(n) fixed<<setprecision(n)
#define popcnt(n) __builtin_popcountll(n)
#define parity(n) __builtin_parityll(n)
#define clz(n) __builtin_clzll(n)
#define ctz(n) __builtin_ctzll(n)

#define sll set<ll>
#define sc set<char>
#define mll map<ll,ll>
#define vll vector<ll>
#define vc vector<char>
#define pll pair<ll,ll>
#define vpll vector<pll>
#define msll multiset<ll>
#define msc multiset<char>
#define vvll vector<vector<ll>>
#define rev reverse

#define pat ll n;cin>>n;
#define pat1 vll a(n);forl(i,n)cin>>a[i];
#define pat2 ll n,k;cin>>n>>k;vll a;forl(i,n) cin>>a[i];
#define tc ll q;cin>>q;while(q--)
#define pats string s;cin>>s;
#define loop forl(i,n)
#define yesno if(flag)cout<<"Yes\n";else cout<<"No\n";

#define p0(a) cout << a << " ";
#define p1(a) cout << a << endl;
#define p2(a,b) cout << a << " " << b << endl;
#define p3(a,b,c) cout << a << " " << b << " " << c << endl;
#define p4(a,b,c,d) cout << a << " " << b << " " << c << " " << d << endl
 
#define MAX LLONG_MAX
#define MIN LLONG_MIN
#define mod1 1000000007
#define mod2 998244353
#define PI 3.1415926535897932384626433832

//**********************************
 
int main(){
    
  ll x;cin>>x;
  pat pat1
  ll cnt[102]={0};
  loop{
      cnt[a[i]]++;
  }
ll in1=-1,in2=-1;
      fore(i,x,101){
          if(cnt[i]==0){
              in1=i;
              break;
          }
      }

      rfore(i,x,0){
          if(cnt[i]==0){
              in2=i;
              break;
          }
      }
  
  ll ans;
  if(in1!=-1 && in2!=-1){
      if(abs(in1-x)<abs(in2-x)){
          ans=in1;
      }else{
          ans=in2;
      }
  }else if(in1!=-1){
      ans=in1;
  }else if(in2!=-1){
      ans=in2;
  }
  cout<<ans<<endl;
}