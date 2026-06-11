#include<iostream>
using namespace std;
int main(){
  char a,b,c,x,y,z;
  cin >> a >> b >> c >> x >> y >> z;
  int ans=0;
  if(a==x){
    ans++;
  }
  if(b==y){
    ans++;
  }
  if(c==z){
    ans++;
  }
  cout << ans << endl;
  return 0;
}
