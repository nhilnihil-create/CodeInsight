#include <bits/stdc++.h>
//debug
#define vecprint(v) cout << "  vector: ";rep(i,v.size())cout << v[i] << " ";cout << endl;
#define setprint(s) cout << "  set: ";for(auto i=s.begin();i!=s.end();i++)cout << *i << " ";cout << endl;
#define mappairprint(s) cout << "  map: ";for(auto i=s.begin();i!=s.end();i++)cout << i->first << " " << i->second << endl;cout << endl;
//reader
#define r1(a) cin>>(a)
#define r2(a,b) cin>>(a)>>(b)
#define r3(a,b,c) cin>>(a)>>(b)>>(c)
//writer
#define w1(a) cout<<(a)<<" "
#define w2(a,b) cout<<(a)<<" "<<(b)<<" "
#define w3(a,b,c) cout<<(a)<<" "<<(b)<<" "<<(c)<<" "
#define wl1(a) cout<<(a)<<endl
#define wl2(a,b) cout<<(a)<<" "<<(b)<<endl
#define wl3(a,b,c) cout<<(a)<<" "<<(b)<<" "<<(c)<<endl
//variable definition
#define pii pair<int,int>
#define pis pair<int,string>
#define psi pair<string,int>
#define pll pair<ll,ll>
//roop
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define rep1(i,n) for (int i = 1; i <= (n); ++i)
#define all(c) c.begin(),c.end()
//term
#define elif else if
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define eb emplace_back
using namespace std;
using ll = long long;
//const
constexpr double PI = 3.141592653589793238462643383279;
vector<int> dx = {1, 0, -1, 0}, dy = {0, 1, 0, -1};


struct L {
  int a, b, c, d;
  L(int a=0, int b=0, int c=0, int d=0): a(a), b(b), c(c), d(d) {}
};

int main() {
  //input
  int s, w;
  cin >> s >> w;
  
  if(s <= w) cout << "unsafe" << endl;
  else cout << "safe" << endl;
  
}