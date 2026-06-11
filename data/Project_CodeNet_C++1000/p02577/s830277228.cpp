#include<bits/stdc++.h>
#define PI 3.141592653589
using namespace std;
using ll = long long;

template<typename T_char>
T_char ToUpper(T_char cX){return toupper(cX);}

int func(int n){
  int tmp = 0;
  while(n>0){
    tmp += n%10;
    n = n/10;
  }
  return tmp;
}
int main(){
  string n; cin >> n;
  int last = n.size();
  int sum = 0;
  for(int i=0; i<last; ++i){
    int num = n[i] - '0';
    sum += func(num);
  }

  if(sum%9==0) cout << "Yes" << endl;
  else cout << "No" << endl;
}