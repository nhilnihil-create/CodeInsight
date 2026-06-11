#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define Sort(a) sort(a.begin(), a.end())
#define Reve(a) reverse(a.begin(), a.end())
#define PI 3.14159265359
typedef long long ll;
const ll MOD = 1e9+7;

/*ll gcd(ll a, ll b){
  if(b==0) return a;
  return gcd(b, a%b);
}*/
/*ll myPow(ll x, ll n, ll m){
  if(n == 0)
    return 1;
  if(n % 2 == 0)
    return myPow(x * x % m, n / 2, m);
  else
    return x * myPow(x, n - 1, m) % m;
}*/

/*ll lcm(ll a, ll b){
  ll g = gcd(a, b);
  b /= g;
  a *= b;
  return a;
}*/
struct UnionFind {
    vector<int> par; // par[i]:iの親の番号　(例) par[3] = 2 : 3の親が2

    UnionFind(int N) : par(N) { //最初は全てが根であるとして初期化
        for(int i = 0; i < N; i++) par[i] = i;
    }

    int root(int x) { // データxが属する木の根を再帰で得る：root(x) = {xの木の根}
        if (par[x] == x) return x;
        return par[x] = root(par[x]);
    }

    void unite(int x, int y) { // xとyの木を併合
        int rx = root(x); //xの根をrx
        int ry = root(y); //yの根をry
        if (rx == ry) return; //xとyの根が同じ(=同じ木にある)時はそのまま
        par[rx] = ry; //xとyの根が同じでない(=同じ木にない)時：xの根rxをyの根ryにつける
    }

    bool same(int x, int y) { // 2つのデータx, yが属する木が同じならtrueを返す
        int rx = root(x);
        int ry = root(y);
        return rx == ry;
    }
};


int main(){
  string s; cin >> s; int64_t k; cin >> k;
  int64_t sz = s.size(); int64_t sz2 = sz*2; 
  int64_t q=1; 
  int64_t ans=0LL;
  int64_t ch = 0LL;
  /*rep(z, sz-1){
    if(s.at(z)!=s.at(z+1)) {ch=1; break;}
  }*/

  //if(ch==0) cout << (sz*k)/2 << endl;
  //if(ch==0) printf("%d\n", (sz*k)/2);
  if(s.at(0)!=s.at(sz-1)){
    rep(i, sz-1){
      int64_t j = i;
      while(s.at(j)==s.at(j+1)) {q+=1; j++;if(j==sz-1) break;}
      ans += q/2;
      q = 1; i = j;
    }
    cout << ans*k << endl;
    //printf("%d\n", ans*k);
  }
  else{
    rep(z, sz-1){
    if(s.at(z)!=s.at(z+1)) {ch=1; break;}
  }
  if(ch==0) cout << (sz*k)/2 << endl;
   else{ int64_t p = sz-1, w=1;
    while(s.at(p)==s.at(p-1)){
      //u += t.at(p+1);
      p--; w++;
      if(p==0) break;
    }
    int64_t d=1, e=0;
    while(s.at(e)==s.at(e+1)){
      d++; e++;
      if(e==sz-1) break;
    }
    int64_t h = (d+w)/2;
    //cout << w << endl; 
    //cout << h << " " << 
    int64_t sum=0;
    ans += h*(k-1)+d/2+w/2;
    //int usz = u.size();
    for(int x=e+1; x<p; x++){
      int y = x;
      while(s.at(y)==s.at(y+1)){
        q++; y++; 
        if(y==p-1) break;
      }
      sum += q/2; q=1; x = y;
    }
    ans += sum*k;
    cout << ans << endl;
    //printf("%d\n", ans);
  }
  }
}