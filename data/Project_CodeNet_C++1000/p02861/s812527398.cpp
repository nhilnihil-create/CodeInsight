#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;  cin >> n;
  vector<pair<int, int>> xy(n);
  for(int i=0; i<n; i++){
    int x, y;  cin >> x >> y;
    xy[i].first = x, xy[i].second = y;
  }
  vector<int> a(n);
  for(int i=0; i<n; i++)  a[i] = i;

  int cnt = 0;
  double sum = 0;
  do{
    for(int i=1; i<n; i++)
      sum += sqrt(pow(xy[a[i-1]].first-xy[a[i]].first, 2)+pow(xy[a[i-1]].second-xy[a[i]].second, 2));
    cnt++;
  }while(next_permutation(a.begin(), a.end()));

  printf("%.10lf\n", sum/cnt);

  return 0;
}
