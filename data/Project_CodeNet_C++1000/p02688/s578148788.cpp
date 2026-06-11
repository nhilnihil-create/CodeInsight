#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, start, end) for (int i = (start); i <= (int)(end); i++)

int main(){
  int n,k;
  cin >> n >> k;
  vector<int> okasi(n);

  rep(i,k){
    int d;
    cin >> d;
    rep(j,d){
      int a;
      cin >> a;
      okasi.at(a - 1) = 1;
    }
  }

  int counter = 0;
  rep(i,n){
    if(okasi.at(i) == 0) counter++;
  }
  cout << counter << endl;

}
