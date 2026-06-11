#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define rep1(i,n) for (int i = 1; i <= (n); ++i)

using namespace std;
using ll = long long;
using P = pair<int,int>;
using ull= unsigned long long;
const ll K_MAX=1e5+5;

int main(){
  int h,w;
  int n;
  cin >>h>>w>>n;
  int l=max(h,w);
  int ans=(n+(l-1))/l;
  
  cout<<ans<<endl;


}
