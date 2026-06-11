/**
*    author:  yuya1234
*    created: 13.07.2020 16:54:10
**/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<(ll)(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=(ll)(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=(ll)(b);i--)
#define FORV(i,v) for(auto i=v.begin(); i!=v.end();i++)

#define SORT(s) sort((s).begin(),(s).end())
#define SORTD(s) sort((s).rbegin(),(s).rend())
#define UNIQUE(v) v.erase( unique(v.begin(), v.end()), v.end() );

#define SZ(x) ((int)(x).size())
#define MEMSET(v, h) memset((v), h, sizeof(v))

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
int gcd(int a,int b){return b?gcd(b,a%b):a;}

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  //std::cout << std::fixed << std::setprecision(15);

  list<string> s;
  string tmp;
  cin>>tmp;
  s.push_back(tmp);

  bool rev=false;
  int n;
  cin>>n;
  REP(i,n){
    int q;
    cin>>q;
    if(q==1){
      rev=!rev;
    }
    else{
      int f;
      string c;
      cin>>f>>c;
      if((!rev && f==1) || (rev && f==2)){
        s.emplace_front(c);
      }
      else{
        s.emplace_back(c);
      }
    }
  }

  if(rev){
    for(auto itr = s.rbegin(); itr != s.rend(); ++itr) {
      reverse((*itr).begin(),(*itr).end());
      cout<<*itr;
    }
  }
  else{
    for(auto itr = s.begin(); itr != s.end(); ++itr) {
      cout<<*itr;
    }
  }
  
  cout<<endl;
  

  return 0;
}