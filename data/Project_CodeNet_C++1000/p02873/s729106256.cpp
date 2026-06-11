#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<(int)(n); i++)
#define all(x) x.begin(), x.end()
#define mod 1000000007
typedef long long ll;

int main(){
  string str;
  cin >> str;
  int left = 0, right = 0;
  ll sum = 0;
  bool reset = true;
  rep(i, str.length()){
    if(str[i] == '<'){
      if(reset){
        if(left == right){
          for(int j=0; j<=left-1; j++){
            sum += j*2;
          }
          sum += left;
        }else{
          int big = max(left, right);
          int small = min(left, right);
          for(int j=0; j<=big; j++){
            sum += j;
          }
          for(int j=0; j<=small-1; j++){
            sum += j;
          }
        }
        left = 1;
        right = 0;
        reset = false;
      }else{
        left++;
      }
    }else{
      right++;
      reset = true;
    }
  }
  if(left == right){
    for(int j=0; j<=left-1; j++){
      sum += j*2;
    }
    sum += left;
  }else{
    int big = max(left, right);
    int small = min(left, right);
    for(int j=0; j<=big; j++){
      sum += j;
    }
    for(int j=0; j<=small-1; j++){
      sum += j;
    }
  }
  cout << sum << endl;
}


