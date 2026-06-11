#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define REP(i, n) for (int i = 0; i < (n); i++)

const long double EPS = 1e-10;
const long long INF = 1e18;
const long double PI = acos(-1.0L);

int main() {
  int n,m;
  cin >> n;
  int a[n-1];
  REP(i, n-1) {
    cin>>a[i];
  }

  map<int,int> umap;

  for(int i=1;i<=n;i++){
    umap[i] = 0;
  }

  //   for(auto i : umap){
  //   cout<<i.first<<" "<<i.second<<"\n";
  // }


  cout<<"\n\n\n\n";  

  for(int i=0;i<n-1;i++){
    umap[a[i]]++;
  }

  for(int i= 1;i<=n;i++){
    cout<<umap[i]<<"\n";
  }
  
  


  
  return 0;
}
