#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int h,n;

  cin >> h >> n;

  vector<int> a(n);

  rep(i,n){
    cin >> a.at(i);
  }
  
  sort(a.begin(),a.end(),greater<>());

  // rep(i,n){
  //   cout << a.at(i) << endl;
  // }

  rep(i,n){
    h-=a.at(i);
    if(h<=0){
      cout << "Yes";
      return 0;
    }
  }

  cout << "No";

}