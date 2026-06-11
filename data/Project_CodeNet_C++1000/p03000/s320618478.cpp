#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,x;
  cin >> n >> x;
  vector<int> vec(n);
  for(int i = 0; i < n; i++){
    cin >> vec.at(i);
  }
  
  int s = 0;
  int count = 1;
    
  for(int i = 0; i < n; i++){
    s+= vec.at(i);
    if(s <= x){
      count++;
    }
    else{
      break;
    }
  }
  cout << count;
}