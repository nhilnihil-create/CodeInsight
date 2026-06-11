#include <iostream>
#include <string>
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, s, n) for(int i = s; i < n; i++)
using namespace std;

int main(){
  int n;
  cin >> n;
  int ans = 0;
  rep2(i, 1, n+1){
    string s = to_string(i);
    if (s.size() % 2 == 1) ans++;
  }
  cout << ans << endl;
  
  return 0;
}