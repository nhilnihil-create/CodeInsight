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
const int MAXN=303030;
int main(){
  fastIO();
  int h,w,m;
  int maxX=0,maxY=0;
  int posX=0,posY;
  int tempMaxX=0,tempMaxY=0;
  cin>>h>>w>>m;
  map<int,int>cols;
  map<int,int>rows;
  map<pair<int,int>,int>coord;
  for(int i=0;i<m;i++){
    int x,y;
    cin>>x>>y;
    cols[x]++,rows[y]++;
    if(cols[x]>maxX)posX=x;
    if(rows[y]>maxY)posY=y;
    maxX=max(maxX,cols[x]);
    maxY=max(maxY,rows[y]);
    coord[make_pair(y,x)]++;
  }
  for(int i=0;i<=MAXN;i++){
    int num=cols[i]-coord[make_pair(posY,i)];
    tempMaxX=max(tempMaxX,num);
  }
  for(int i=0;i<=MAXN;i++){
    int num=rows[i]-coord[make_pair(i,posX)];
    tempMaxY=max(tempMaxY,num);
  }
  cout<<max(tempMaxY+maxX,tempMaxX+maxY)<<endl;
  return 0;
}
