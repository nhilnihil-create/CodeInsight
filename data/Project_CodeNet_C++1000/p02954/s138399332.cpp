#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;
#define ll long long

int main(void){
  string str;
  cin >> str;
  int num = str.size();
  vector<int> ans(num,0);
  int p = 0;
  for(int i = 0;i < num;i ++){
    if(str[i] == 'R'){
      p ++;
    }else{
      if(p>0){
        ans[i] = ans[i]  +floor(p/2);
        ans[i-1] = ans[i-1] + floor(p/2) + (p % 2);
      }
      p = 0;
    }
  }
  p = 0;
  for(int i = 0;i < num;i ++){
    if(str[num-1-i] == 'L'){
      p++;
    }else{
      if(p>0){
        ans[num-i-1] = ans[num-i-1] + floor(p/2);
        ans[num-i] = ans[num-i] + floor(p/2) + (p % 2);
      }
      p = 0;
    }
  }
  for(int i = 0;i < num;i ++){
    cout << ans[i] << ' ';
  }
  
  
  return 0;
}