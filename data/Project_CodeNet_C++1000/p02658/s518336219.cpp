#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(void){
  ll n;
  cin >> n;
  ll row[n];
  ll result=1;
  for(int i=0;i<n;i++){
    cin >> row[i];
    if(row[i] == 0){
      cout << 0 << endl;
      return 0;
    }
  }  
  for(int i=0;i<n;i++){
    if(row[i] <= 1000000000000000000/result){
      result *= row[i];
    }else{
      cout << -1 << endl;
      return 0;
    }
  }  
  cout << result << endl;
  return 0;
  
}       