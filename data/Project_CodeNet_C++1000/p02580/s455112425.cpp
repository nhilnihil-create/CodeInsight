#include <bits/stdc++.h>
using namespace std;

int main() {
  int h,w,m;
  cin>>h>>w>>m;

  int height[h];
  int width[w];
  for(int i=0; i<h; i++) height[i]=0;
  for(int i=0; i<w; i++) width[i]=0;

  vector<pair<int, int>> bomb;
  for(int i=0; i<m; i++) {
    int a,b;
    cin>>a>>b;
    height[a-1]++;
    width[b-1]++;
    bomb.push_back(make_pair(a-1, b-1));
  }

  int hmax = *max_element(height, height+h);
  int wmax = *max_element(width, width+w);
  int ans = hmax+wmax;

  int64_t hcount = 0;
  int64_t wcount = 0;
  for(int i=0; i<h; i++) {
    if(height[i]==hmax) hcount++;
  }
  for(int i=0; i<w; i++) {
    if(width[i]==wmax) wcount++;
  }

  int64_t count = 0;
  for(int i=0; i<m; i++) {
    int a = bomb[i].first;
    int b = bomb[i].second;
    if(height[a]==hmax && width[b]==wmax) count++;
  }

  if(count==hcount*wcount) ans--;


  cout<<ans<<endl;

  return 0;
}