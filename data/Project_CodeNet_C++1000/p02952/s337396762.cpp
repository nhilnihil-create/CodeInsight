#include <iostream>
#include <string>
using namespace std;
int main(){
  int n;
  cin >> n;
  int i;
  int cnt = 0;
  for(i=1;i<=n;i++){
    string x = to_string(i);
    int a = x.size();
    if(a==1||a==3||a==5||a==7) cnt++;
  }
  cout << cnt << "\n";
  return 0;
}