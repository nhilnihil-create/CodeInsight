#include <bits/stdc++.h>
#include <string>
#include <vector>
#include <algorithm>
#define rep(i,w) for (int i = 0;i < (w); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
using ld = long double; 
int INF = 1e9;
int main(){
  int n;cin >> n;
  vector<P> pos(n);
  vector<int> num(n);
  rep(i,n){
    cin >> pos[i].first >> pos[i].second;
    num[i] = i+1;
  }
  ld sum = 0;
  do{
    rep(i,n-1){
      sum += sqrt(ld((pos[num[i]-1].first - pos[num[i+1]-1].first)*(pos[num[i]-1].first - pos[num[i+1]-1].first)+(pos[num[i]-1].second - pos[num[i+1]-1].second)*(pos[num[i]-1].second - pos[num[i+1]-1].second)));
      }
  }while(next_permutation(num.begin(),num.end()));
  rep(i,n) sum /= (i+1);
  printf("%.6Lf\n",sum);


}