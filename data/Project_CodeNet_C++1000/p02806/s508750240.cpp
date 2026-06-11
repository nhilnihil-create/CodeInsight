#include <bits/stdc++.h>
using namespace std;


int main(void){
  int n;
  cin >> n;
  vector<string> title(n);
  vector<int> length(n);
  for(int i = 0; i < n; i++){
    cin >> title[i];
    cin >> length[i];    
  }
  
  string stop_title;
  cin >> stop_title;
  int flag = 0, sum = 0;
  for(int i = 0; i < n; i++){
    if(flag == 1){
      sum += length.at(i);
    }
    if(title.at(i) == stop_title){
      flag = 1;
    }
    
  }
  cout << sum << endl;
 return 0; 
}