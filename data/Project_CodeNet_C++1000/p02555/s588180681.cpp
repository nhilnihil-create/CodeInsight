/* In the name of Anton */

/*
* Motto :)
*
*
*
*
*
*/

#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<n;i++)
#define repa(i,a,n) for(int i=a;i<=n;i++)
#define repb(i,a,n) for(int i=a;i>=n;i--)
#define trav(x,a) for(auto &x: a)
#define all(x) x.begin(),x.end()
#define sz(x) (int)(x).size()
#define fst first
#define snd second
#define pb push_back
#define mp make_pair
#define vt vector
typedef long double ld;
typedef pair <int,int> pii;
typedef vector <int> vi;
typedef long long ll;

template<class A> void read(vt<A>& v);
template<class T> void read(T& x){
  cin>>x;
}

void read(double &d){
  string t;
  read(t);
  d=stod(t);
}
void read(long double &d){
  string t;
  read(t);
  d=stold(t);
}

template<class H, class... T> void read(H &h, T&...t){
  read(h);
  read(t...);
}

template <class A> void read(vt<A> &x){
  trav(a,x)
    read(a);
}

string to_string(char c){
  return string(1,c);
}

string to_string(bool b){
  return b?"true":"false";
}

string to_string(const char* s){
  return string(s);
}

string to_string(string s){
  return string(s);
}

string to_string(vt<bool> v){
  string res;
  rep(i,sz(v)){
    res+=char('0'+v[i]);
  }
  return res;
}

template<class T> string to_string(T v){
  bool f=1;
  string res;
  trav(x,v){
    if(!f)
      res+=' ';
    f=0;
    res+=to_string(x);
  }
  return res;
}

template<class A> void write(A x){
  cout<<to_string(x);
}

template<class H, class...T> void write(const H& h, const T&...t){
  write(h);
  write(t...);
}

void print(){
  write("\n");
}

template<class H, class...T> void print(const H& h, const T&...t){
  write(h);
  if(sizeof...(t))
    write(' ');
  print(t...);
}

/* -----------------------------------------------------------------------------------------------*/

const int mxN=2005;
const ll mod=1e9+7;
ll dp[mxN];

void pre(){
  rep(i,mxN){
    dp[i]=1;
  }

  dp[0]=0;
  dp[1]=0;
  dp[2]=0;

  for(int i=3;i<mxN;i++){
    for(int j=3;j<mxN;j++){
      if(i+j<mxN){
        dp[i+j]=(dp[i+j]+dp[i])%mod;
      }
    }

  }
}

void solve(){
  int s; read(s);
  print(dp[s]);
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  pre();
  int t=1;
  // read(t);
  rep(i,t) solve();
  return 0;
}
