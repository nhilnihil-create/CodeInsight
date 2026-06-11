#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  int count = 0;
  cin >> N;
    
  vector<string> data(N);
  vector<string> Gdata(N);
  
  for(int i = 0;i < N ;i++){
    cin >> data.at(i);
  }
  
  sort(data.begin(), data.end());
  data.erase(unique(data.begin(), data.end()),data.end());
  
  cout << data.size() << endl;
}