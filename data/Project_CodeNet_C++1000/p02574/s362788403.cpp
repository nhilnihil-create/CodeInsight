
#include<bits/stdc++.h>
using namespace std ;


#define vt vector
#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()
#define ll long long
#define ld long double
#define ar array
#define inf() ifstream cin("d.txt")
#define onf() ofstream cout("test.txt")
#define mod 1000000007
#define pb push_back
#define endl cout<<"\n";
#define prt1(a) cout<<a<<" "
#define prt2(a,b) cout<<a<<" "<<b<<" "
#define prt3(a,b,c) cout<<a<<" "<<b<<" "<<c<<" "
#define in(a) cin>>a
#define inn(a,b) cin>>a>>b
#define innn(a,b,c) cin>>a>>b>>c 
#define rep(i,st,end) for(int i=st;i<end;i++)
#define repv(i,st,end) for( i=st;i>=end;i--)
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define TEST ll tc;cin>>tc;while(tc--)
#define EACH(x, a) for (auto& x: a)

template<class A> void read(vt<A>& v);
template<class A, size_t S> void read(ar<A, S>& a);
template<class T> void read(T& x) {
    cin >> x;
}
void read(double& d) {
    string t;
    read(t);
    d=stod(t);
}
void read(long double& d) {
    string t;
    read(t);
    d=stold(t);
}
template<class H, class... T> void read(H& h, T&... t) {
    read(h);
    read(t...);
}
template<class A> void read(vt<A>& x) {
    EACH(a, x)
        read(a);
}
template<class A, size_t S> void read(array<A, S>& x) {
    EACH(a, x)
        read(a);
}
#define debug(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }

void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
    cerr << *it << " = " << a <<"\n";
    err(++it, args...);
}

ll spf[1000005]={0} ;
void sieve()
{
   spf[1] = 1;
   for(int i = 2 ; i<1000005;i++)
      spf[i] = i;

      for(int i = 4 ; i<1000005;i+=2)
      spf[i] = 2;

      for(int i = 3 ;i*i<1000005;i++)
      {
         if(spf[i] ==i)
         {
            for(int j=i*i;j<1000005;j+=i)
            {
               if(spf[j]==j)
               spf[j] = i;
            }
         }
      }
   }

map<ll,ll>prime ;

void primefactor(ll x)
{
   ll cnt= 0;
   set<ll>s;
   unordered_map<ll,ll>mp;

   while(x!=1)
   {
    s.insert(spf[x]);
      x=x/spf[x];
   }
   for(auto it: s)
    prime[it]++;
}


void solve()
{

  ll n;
  read(n);
  vt<ll>v(n) ;
  read(v);
  ll g= v[0];
  rep(i,1,n)
  g=__gcd(g,v[i]);

  rep(i,0,n)
  primefactor(v[i]);
  // for(auto it:prime)
  //   cout<<it.first<<" "<<it.second<<"\n";

  ll f= 0;
  for(auto it:prime)
  {
    if(it.second>1)
    {
      f= 1;
      break ;
    }
  }
  if(f==0)
    cout<<"pairwise coprime";
  else if(g==1)
    cout<<"setwise coprime";
  else
    cout<<"not coprime";


}


 int main()
 {
    fio;
    ll k = 1;
    ll tc = 1;
    sieve();
    // cin>>tc;
    while(tc--){
       // cout<<"Case #"<<k<<": ";k++;
        solve();
        endl;
    }
    
 }


