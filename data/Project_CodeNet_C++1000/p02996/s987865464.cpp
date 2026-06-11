#include<bits/stdc++.h>
using namespace std;
int main(){
  int n; cin >> n;
  vector<pair<long long, long long>> task1;
  vector<pair<long long, long long>> task2;
  for(int i = 0; i < n; i++){
    long long a,b; cin >> a >>b;
    task1.push_back(make_pair(a,b));
    task2.push_back(make_pair(b,a));
  }
  sort(task1.begin(),task1.end());
  sort(task2.begin(),task2.end());
  long long ans = 0;
  for(int i = 0; i < n; i++){
    if(ans + task1.at(i).first > task1.at(i).second)
      break;
    else
      ans += task1.at(i).first;
    if(i == n -1){
      cout << "Yes";
      return 0;
    }
  }
  ans = 0;
  for(int i = 0; i < n; i++){
    if(ans + task2.at(i).second > task2.at(i).first)
      break;
    else
      ans += task2.at(i).second;
    if(i == n -1){
      cout << "Yes";
      return 0;
    }
  }
  cout << "No";
  
  
}
  