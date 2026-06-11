#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
  int a,b;
  cin >> a >> b;
  int c,ans=0;
  for(int i=0;i<a;i++){
    cin >> c;
    if(c>=b)ans++;
  }
  cout << ans;
}
