#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<(int)(n); i++)
#define all(x) x.begin(), x.end()
#define mod 1000000007
typedef long long ll;

int main(){
  int n;
  cin >> n;
  ll sum = 0;
  for(int i=1; i<=9; i++){
    for(int j=1; j<=9; j++){
      int a=0, b=0;
      if(i == j){
        if(i <= n){
          a++;
          b++;
        }
      }
      if(10*i+j <= n) a++;
      if(10*j+i <= n) b++;
      for(int k=1; k<=4; k++){
        for(int num=0; num<pow(10, k); num++){
          string numStr = "";
          int zeroNum = k-to_string(num).length();
          rep(m, zeroNum) numStr += "0";
          numStr += to_string(num);
          string str = "";
          str += to_string(i);
          str += numStr;
          str += to_string(j);
          if(stoi(str) <= n) a++;
          str = "";
          str += to_string(j);
          str += numStr;
          str += to_string(i);
          if(stoi(str) <= n) b++;
        }
      }
      sum += a*b;
    }
  }
  cout << sum << endl;
  return 0;
}         