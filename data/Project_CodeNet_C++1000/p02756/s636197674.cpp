#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double lld;
ll MOD = (1e9)+7;
//#pragma GCC target ("avx2")
//#pragma GCC optimization ("O3")
//#pragma GCC optimization ("unroll-loops")
inline void fastIO(){
  ios_base::sync_with_stdio(0);cin.tie(0);
}
template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << '{'; string sep; for (const auto &x : v) os << sep << x, sep = ", "; return os << '}'; }
template<typename T, size_t size> ostream& operator<<(ostream &os, const array<T, size> &arr) { os << '{'; string sep; for (const auto &x : arr) os << sep << x, sep = ", "; return os << '}'; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }

void debug_out() { cerr << endl; }
template<typename Head, typename... Tail> void debug_out(Head H, Tail... T) { cerr << ' ' << H; debug_out(T...); }

#ifdef LOCAL
#define debug(...) cerr << "(" << #__VA_ARGS__ << "):", debug_out(__VA_ARGS__)
#else
#define debug(...) 47
#endif

int main(){
  fastIO();
  string s;
  cin>>s;
  int q;
  cin>>q;
  bool pos=false;
  string prefix="",suffix="";
  int inv=0;
  while(q--){
    int com;
    cin>>com;
    if(com==1){
      inv++;
      pos=!pos;
    }else{
      int side;
      char add;
      cin>>side>>add;
      if(side==1){
        if(!pos){
          suffix=add+suffix;
        }else{
          prefix+=add;
        }
      }else{
        if(!pos){
          prefix+=add;
        }else{
          suffix=add+suffix;
        }
      }
    }
  }
  if(inv%2==0){
    cout<<suffix+s+prefix<<endl;
  }else{
    reverse(prefix.begin(),prefix.end());
    reverse(suffix.begin(),suffix.end());
    reverse(s.begin(),s.end());
    cout<<prefix+s+suffix<<endl;
  }
  return 0;
}
