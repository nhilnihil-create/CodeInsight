#include <bits/stdc++.h>
using namespace std;
using P = pair<int,int>;

int main(){
  int n;
  cin >> n;
  vector<P> dot(n);
  for(int i=0; i<n; ++i){
    int x, y;
    cin >> x >> y;
    dot[i] = make_pair(x,y);
  }
  sort(dot.begin(),dot.end());
  int ans = n;
  for(int i=0; i<n; ++i){
    for(int j=i+1; j<n; ++j){
      int nans = n-1;
      int p = dot[j].first -dot[i].first;
      int q = dot[j].second -dot[i].second;
      for(int k=i+1; k<n; ++k) for(int l=k+1; l<n; ++l){
        if(dot[k].first + p == dot[l].first &&
           dot[k].second + q == dot[l].second){
          --nans;
        }
      }
      ans = min(nans, ans);
    }
  }
  cout << ans << endl;
}