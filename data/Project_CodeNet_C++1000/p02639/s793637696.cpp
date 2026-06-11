#include<iostream>
#include<vector>
using namespace std;

int main(){
  vector<int> x(5);
  int cnt = 0;
  for(int i = 0;i < 5;i++){
    cin >> x[i];
    cnt++;
    if (x[i] == 0) break;
  }
  cout << cnt << endl;
  return 0;
}