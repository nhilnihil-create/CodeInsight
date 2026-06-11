#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0;i < n;i++)
using ll = long long;

int main(){
  int x; cin >>x;
  for(int a = -120; a<=120; a++){
    for(int b = -120; b<=120; b++){
      if(a*a*a*a*a-b*b*b*b*b==x){
        cout << a << " " << b << endl;
        return 0;
      }
    }
  }
  return 0;
}