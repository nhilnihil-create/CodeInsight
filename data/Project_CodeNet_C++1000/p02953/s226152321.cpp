#include <iostream>
#include <vector>
#include <string>;
#define ll long lomg

using namespace std;
#define ll long long
int max(int a,int b){
  if(a > b){
    return a;
  }else{
    return b;
  }
}

int main(void){
  ll num;
  cin  >> num;
  vector<ll> high(num);
  for(int i = 0;i < num;i ++){
    cin >> high[i];
  }
  ll most = 0;
  string ans = "Yes";
  for(int i = 0;i < num;i ++){
    if(most > high[i]){
      ans = "No";
    }else if(most < high[i]-1){
      most = high[i]-1;
    }
  }
  
  cout << ans << endl;
  return 0;
}