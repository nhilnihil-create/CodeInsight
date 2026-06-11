#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define repone(i,n) for(int i=1;i<(int)(n);++i)
#define repo(i,o,n) for(int i=o;i<(int)(n);++i)
#define Rep(j,n) for(int j=0;j<(int)(n);++j)
#define Repo(j,o,n) for(int j=o;j<(int)(n);++j)
#define Repone(j,n) for(int j=1;j<(int)(n);++j)
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define int long long
#define pb(a) push_back(a)
#define eraser(v,i) (v).erase(v.begin()+(i))
#define pbpair(a,b) push_back(make_pair(a,b))
#define Little 1
const long long INF = 1LL<<60;
#define pairint pair<int,int>
signed main(){
  int x,y,z=1;
  std::cin >> x;
  std::vector<int> v(x);
  rep(i,x)std::cin >> v[i];
  sort(all(v));
  rep(i,x){
    if(log10(z)+log10(v[i])<=18&&z*v[i]<=1000000000000000000){
      z*=v[i];
    }else {
      std::cout << -1 << '\n';
      return 0;
    }
  }
  std::cout << z << '\n';
}
