#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double lld;
ll MOD = (1e9)+7;
const int dr[] = {+1, -1, +0, +0, +1, -1, +1, -1};
const int dc[] = {+0, +0, +1, -1, +1, -1, -1, +1};
const int kx[] = {+1, +2, -1, -2, +1, +2, -1, -2};
const int ky[] = {+2, +1, +2, +1, -2, -1, -2, -1};
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
  int h,w,k,ans=0;
  cin>>h>>w>>k;
  char grid[h][w];
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      cin>>grid[i][j];
    }
  }
  for(int row=0;row<pow(2,h);row++){
    for(int col=0;col<pow(2,w);col++){
      char temp[h][w];
      int cnt=0;
      for(int i=0;i<h;i++){
	for(int j=0;j<w;j++){
	  temp[i][j]=grid[i][j];
	}
      }
      for(int bit=0;bit<h;bit++){
	if(row&(1<<bit)){
	  for(int i=0;i<w;i++){
	    temp[bit][i]='?';
	  }
	}
      }
      for(int bit=0;bit<w;bit++){
	if(col&(1<<bit)){
	  for(int i=0;i<h;i++){
	    temp[i][bit]='?';
	  }
	}
      }
      for(int i=0;i<h;i++){
	for(int j=0;j<w;j++){
	  if(temp[i][j]=='#')cnt++;
	}
      }
      if(cnt==k)ans++;
    }
  }
  cout<<ans<<endl;
  return 0;
}
