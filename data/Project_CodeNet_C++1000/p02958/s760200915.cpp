#include <iostream>
using namespace std;
int main(){
  int a,b,ans=0;
  cin >> a;
  for(int i = 0;i<a;i++){
    cin >> b;
    if(b!=(i+1))ans++;
  }
  if(ans<3)cout << "YES";
  else cout << "NO";
}
