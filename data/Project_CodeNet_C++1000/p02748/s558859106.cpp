#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int a,b,m;
  cin>>a>>b>>m;
  vector<int> A(a);
  vector<int> B(b);
  rep(i,a){
    cin>>A[i];
  }
  rep(i,b){
    cin>>B[i];
  }
  int min_cost=200010;
  rep(i,m){
    int x,y,c,now_cost;
    cin>>x>>y>>c;
    now_cost=A[x-1]+B[y-1]-c;
    min_cost=min(min_cost,now_cost);
  }
  sort(A.begin(),A.end());
  sort(B.begin(),B.end());
  int z = A[0] + B[0];
  min_cost=min(min_cost,z);
  cout<<min_cost<<endl;
}