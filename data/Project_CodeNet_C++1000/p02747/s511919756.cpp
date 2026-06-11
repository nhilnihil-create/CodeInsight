#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;


int main(void){
  string s; cin >> s;
  int x = s.size();
  for(int i = 0; i < x; i++){
    if(i % 2 == 0 && s.at(i) != 'h'){
      cout << "No" << endl;
      return 0;
    }
    else if(i % 2 == 1 && s.at(i) != 'i'){
      cout << "No" << endl;
      return 0;
    }
  }
  if(s.at(x - 1) != 'i'){
    cout << "No" << endl;
    return 0;
  }
  cout << "Yes" <<endl;
  return 0;
}
