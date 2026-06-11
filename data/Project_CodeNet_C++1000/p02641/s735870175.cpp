#include<iostream>
#include<string>
#include <numeric>
#include <algorithm>
#include<queue>
#include<vector>
using namespace std;
typedef pair<int, int> P;

int main(){
  int x, n, min=100, num;
  cin >> x >> n;
  vector<int> p(n);
  for(int i=0; i<n; i++){
    cin >> p[i];
  }
  for(int i=0; i<=2*x; i++){
    if(find(p.begin(), p.end(), i) != p.end()) continue;
    if(abs(x-i) < min){
      min = abs(x-i);
      num = i;
    }else if(abs(x-i) == min){
      if(i < num) num = i;
    }
  }
  cout << num << endl;
  return 0;
}