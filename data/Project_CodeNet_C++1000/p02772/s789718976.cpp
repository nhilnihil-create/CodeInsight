#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n) ;i++)
using namespace std;
using p=pair<int,int>;

int main() {
  int n;
  cin >> n;
  int m=0;
  rep(i,n){
    int a;
    cin >> a;
    if(a%2==0){
      if(a%3 != 0 && a%5 != 0){
        m++;
      }
    }
  }
  if(m==0){
    cout << "APPROVED" << endl;
  }
  else {
    cout << "DENIED" << endl;
  }
  return 0;

}
