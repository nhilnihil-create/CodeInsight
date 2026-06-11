#include<iostream>
using namespace std;

int main(){
  long long a,b;
  cin >> a >> b;
  if(a==1 || b==1){
    cout << 1;
    return 0;
  }
  long long ans = a*b;
  if(ans%2==0) cout << ans/2;
  else cout << ans/2 +1;
}