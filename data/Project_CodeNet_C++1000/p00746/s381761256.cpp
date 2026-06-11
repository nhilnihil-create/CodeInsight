#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<map>
#include<set>
#define rep(i,n) for(int i=0;i<n;i++)
#define INF 1<<29
using namespace std;
typedef pair<int,int> pre;

int main(){
  int n,a,b;
  int max_x=0,max_y=0,min_x=1<<30,min_y=1<<30;
  pre ans[1000];
  while(cin >> n && n){
    max_x=0,max_y=0,min_x=1<<30,min_y=1<<30;
    ans[0].first = 0;
    ans[0].second = 0;
    for(int i=0;i<n-1;i++){
      cin >> a >> b;
      ans[i+1] = ans[a];
      if(b == 0)ans[i+1].first--;
      else if(b == 1)ans[i+1].second++;
      else if(b == 2)ans[i+1].first++;
      else if(b == 3)ans[i+1].second--;
      max_x = max(max_x,ans[i+1].first);
      min_x = min(min_x,ans[i+1].first);
      max_y = max(max_y,ans[i+1].second);
      min_y = min(min_y,ans[i+1].second);
    }
    cout << max_x-min_x+1 << " " << max_y-min_y+1 << endl;

  }
  return 0;
}