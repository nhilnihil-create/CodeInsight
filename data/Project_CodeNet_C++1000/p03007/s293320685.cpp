#include <bits/stdc++.h>
#include <string>
#include <vector>
#include <algorithm>
#define rep(i,w) for (int i = 0;i < (w); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
int INF = 1e9;

int main(){
  int n;cin >> n;
  vector<int> a(n);
  rep(i,n) cin >> a[i];
  sort(a.begin(),a.end());
  vector<P> p;
  for(int i = 1;i < n-1;i++){
    if(a[i]>0){
      p.emplace_back(a[0],a[i]);
      a[0] -= a[i];
    }else{
      p.emplace_back(a[n-1],a[i]);
      a[n-1] -= a[i];
    }
  }
  cout << a[n-1] - a[0] << endl;
  for(auto q:p) printf("%d %d\n",q.first,q.second);
  printf("%d %d\n",a[n-1],a[0]);
  
}