#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main(){
  int n;
  int x[100000];
  int L[100000];
  pair<int,int> x_se[100000];

  cin >> n;
  for(int i = 0; i < n; i++) cin >> x[i] >> L[i];

  // for(int i = 0; i < n; i++) cout << x[i] << L[i] << endl;

  for(int i = 0; i < n; i++){
    // pair (end, start)
    x_se[i] = make_pair(x[i]+L[i],x[i]-L[i]);
    // cout << x_se[i].first << "," << x_se[i].second << endl;
  }

  sort(begin(x_se),begin(x_se) + n);

  for (int i = 0; i < n; i++){
    // cout << x_se[i].first << "," << x_se[i].second << endl;
  }

  int counter = 1;
  int now = x_se[0].first;
  for (int i = 1; i < n; i++){
    // now = x_se[i-1].first;
    if(x_se[i].second >= now){
      counter ++;
      now = x_se[i].first;
      // continue;
    }else{
      // now = x_se[i-1].first;
    }
  }

  cout << counter << endl;

  



  return 0;
}