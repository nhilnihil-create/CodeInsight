#include<bits/stdc++.h>
#define rep(i,n) for (int i =0; i <(n); i++)
using namespace std;
using ll = long long;
using P = pair<ll,ll>;

int main(){
  int N;
  cin >> N;
  
  vector<int>V(N);
  rep(i,N)cin >> V[i];
  
  sort(V.begin(),V.end()); //昇順にソートすると、最後に一番価値が高いのが残る
  double ans = V[0];
  rep(i,N){
    ans = (ans + V[i]) / 2;
  }
  cout << setprecision(5) << ans <<endl;

  
}