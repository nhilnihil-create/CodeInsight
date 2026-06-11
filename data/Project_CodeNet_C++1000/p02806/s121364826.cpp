#include <iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

int main(void){
  int n;
  cin >> n;
  int sum = 0;
  vector<pair<string,int>> p(n);
  for(int i = 0;i < n;i++){
       cin >> p[i].first >> p[i].second;
       sum += p[i].second;
  }
  string x;
  cin >> x;
  for(int i = 0;i < n;i++){
        sum -= p[i].second;
        if(x == p[i].first)break;
  }
  cout << sum << endl;
}
