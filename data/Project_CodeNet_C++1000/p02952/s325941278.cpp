#include <iostream>
using namespace std;
int main(){
  int a,ans=0;
  cin >> a;
  for(int i = 1;i<a+1;i++){
    if(i/10==0)ans++;
    else if(i/1000==0&&i/100!=0)ans++;
    else if(i/100000==0&&i/10000!=0)ans++;
  }
  cout << ans;
}