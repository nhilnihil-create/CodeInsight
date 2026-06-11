#include <iostream>
#include <string>
#include <set>

using namespace std;

set <string> old;

int main() {

  int n, ans = 0;
  string str;
  cin >> n;
  for(int i = 1;i <= n;i++){
    cin >> str;
    ans++;
    if(old.find(str) != old.end()){
      ans--;
    }else{
      old.insert(str);
    }
  }
  cout << ans;
  return 0;
}
