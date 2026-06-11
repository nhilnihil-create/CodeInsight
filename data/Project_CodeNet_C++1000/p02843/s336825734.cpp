#include<bits/stdc++.h>
#define PI 3.141592653589
using namespace std;
using ll = long long;

template<typename T_char>
T_char ToUpper(T_char cX){return toupper(cX);}

int main(){
  int x;
  cin >> x;
  int cp_x = x;
  
  int res = cp_x/=100;
  int num = res *100;
  int a = x-num;
  if(res*5>=a) cout << 1;
  else cout << 0;
    
}