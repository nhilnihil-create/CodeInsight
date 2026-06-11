#include <bits/stdc++.h>
using namespace std;
#define rep(i,c) for(int i=0;i<c;++i)
#define PI 3.14159265358979323846264338327950L
typedef unsigned long long uint64;
using namespace std;
using ll = long long;
int main(){
  int a,b;
  cin >> a >> b;
  if(a>b){
    for(int i = 0;i<a;i++){
      cout << b;
    }
    cout << endl;
  }else{
    for(int i= 0;i<b;i++){
      cout << a ;
    }
    cout << endl;
  }
  return 0;
}