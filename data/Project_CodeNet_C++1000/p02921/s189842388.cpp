#include<iostream>
using namespace std;
int main(){
  int ans=0;
  char a,b,c,d,e,f;
  cin >> a >> b >> c;
  cin >> d >> e >> f;
  if(a==d){
    ans++;
  }
  if(b==e){
    ans++;
  }
  if(c==f){
    ans++;
  }
  cout << ans << endl;
}