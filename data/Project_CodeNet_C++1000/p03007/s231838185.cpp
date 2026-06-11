#include <bits/stdc++.h>
using namespace std;
using P = pair<int,int>;

void printvP(vector<P> ans){
  int n = ans.size();
  for(int i=0; i<n; ++i){
    printf("%d %d\n",ans[i].first,ans[i].second);
  }
}

int main(){
  int n;
  cin >> n;
  vector<int> an(n);
  for(int i=0; i<n; ++i) cin >> an[i];
  sort(an.begin(),an.end());
  if(an[n-1] <= 0){
    vector<P> ans;
    for(int i=1; i<n-1; ++i){
      ans.push_back(P(an[n-1],an[i]));
      an[n-1] -= an[i];
    }
    ans.push_back(P(an[n-1],an[0]));
    an[n-1] -= an[0];
    printf("%d\n", an[n-1]);
    printvP(ans);
    return 0;
  }
  if(an[0] >= 0){
    vector<P> ans;
    for(int i=1; i<n-1; ++i){
      ans.push_back(P(an[0],an[i]));
      an[0] -= an[i];
    }
    ans.push_back(P(an[n-1],an[0]));
    an[n-1] -= an[0];
    printf("%d\n", an[n-1]);
    printvP(ans);
    return 0;
  }
  int num;
  int ans1 = 0;
  for(int i=0; i<n; ++i){
    ans1 += abs(an[i]);
    if(i<n-1 && an[i]<0 && an[i+1] >=0){
      num = i;
    }
  }
  printf("%d\n", ans1);
  for(int i=1; i<=num; ++i){
    printf("%d %d\n", an[n-1], an[i]);
    an[n-1] -= an[i];
  }
  for(int i=num+1; i<n-1; ++i){
    printf("%d %d\n", an[0], an[i]);
    an[0] -= an[i];
  }
  printf("%d %d\n", an[n-1], an[0]);
}