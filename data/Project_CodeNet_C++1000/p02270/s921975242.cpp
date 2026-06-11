#include <iostream>
#include <vector>
#define BIG 1000000000

using namespace std;

bool okay(int p, int k, vector<int> weights){
  int i;
  int sum = 0;
  int num_of_tracks = 1;
  int len = weights.size();
  for (i = 0; i < len; ++i){
    if(sum + weights.at(i) < p){
      sum += weights.at(i);
    }else{
      num_of_tracks++;
      if(weights.at(i) < p){
        sum = weights.at(i);
      }else{
        return false;
      }
    }
  }
  if(num_of_tracks <= k){
    return true;
  }
  return false;
}

int main(){
  int n, k, i;
  cin >> n >> k;
  vector<int> weights;
  for (i = 0; i < n; ++i){
    int w;
    cin >> w;
    weights.push_back(w);
  }
  int l = 0, h = BIG;
  while(l+1 < h){
    int m = (l+h)/2;
    if(okay(m, k, weights)) h = m; else l = m;
  }
  cout << l << endl;
}