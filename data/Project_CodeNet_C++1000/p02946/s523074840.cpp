#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;

int main() {
  int k,x;
  cin >> k >> x;
  int a=x+k-1;
  for(int i = x-(k-1); i <=a; i++){
    if(i<a){
      cout<<i<<" ";
    }else{
      cout<<i<<endl;
    }
  }
}