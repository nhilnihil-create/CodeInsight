#include <iostream>
#include <string>

using namespace std;

int main() {

  int n, perm, ans = 0;
  cin >> n;
  for(int i = 1;i <= n;i++){
    cin >> perm;
    if(perm != i){
      ans++;
    }
  }
  if(ans < 3){
    cout << "YES";
  }else{
    cout << "NO";
  }
  return 0;
}
