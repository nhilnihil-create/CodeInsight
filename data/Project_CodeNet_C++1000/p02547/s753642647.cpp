#include <bits/stdc++.h>
using namespace std;


int main() {

  int N;
  int ans = 0;

  cin >> N;
  for(int i=0;i<N;++i){
    int a,b; cin >> a >> b;
    if(a == b){
      ans++;
    }else{
      ans = 0;
    }

    if(ans == 3){
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
  return 0;
}
