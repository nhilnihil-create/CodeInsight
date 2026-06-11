#include<iostream>
#include<climits>
#include<algorithm>
using namespace std;
struct mat{
  int w,h;
};
vector<mat> v;
int memo[101][101];

int solve(int l,int r){
  if(memo[l][r] > 0)return memo[l][r];
  //cout << l << ' ' << r << endl;
  if(l == r)return 0;
  int ret = INT_MAX;
  for(int i = l; i < r; i++){
    int ans = solve(l,i) + solve(i+1,r) + v[l].h * v[i].w * v[r].w;
    ret = min(ret,ans);
  }
  return memo[l][r] = ret;
}
int main(){
  fill(*memo,*(memo+101),-1);
  int n;
  cin >> n;
  for(int i = 0;i < n;i++){
    int r,c;
    cin >> r >> c;
    v.push_back({c,r});
  }
  cout << solve(0,n-1) << endl;
}