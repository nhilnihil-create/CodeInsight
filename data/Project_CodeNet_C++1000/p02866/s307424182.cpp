#include<bits/stdc++.h>
using namespace std;
int64_t MAGIC = 998244353;

int64_t power_a(int64_t a, int64_t n){
  int64_t res = 1;
  while(n){
    if(n&1){
      res = (res* a) % MAGIC;
    }
    n = n >> 1;
    a = (a*a)%MAGIC;
  }
  if(a == 0 && n == 0){
    return 0;
  }else{
    return res;
  }
}
    
    
int main(){
  int64_t n;
  cin >> n;
  vector<int64_t> d(n);
  int64_t maxd = 0;
  for(int i=0;i<n;i++){
    cin >> d.at(i);
    if(maxd < d.at(i)){
      maxd = d.at(i);
    }
  }
  bool validflag = true;
  if(d.at(0) != 0) validflag = false;
  
  vector<int> check(maxd+1);
  
  for(int i=0;i<n;i++){
    check.at(d.at(i))++;
  }
  
  int64_t result = 1;
  if(check.at(0) != 1){
    validflag = false;
  }else{
    for(int i=0;i<maxd;i++){
      result = (result * power_a(check.at(i),check.at(i+1))) % MAGIC;
    }
  }
  if(validflag){
    cout << result << endl;
  }else{
    cout << "0" << endl;
  }
}
    
    
    
  
  