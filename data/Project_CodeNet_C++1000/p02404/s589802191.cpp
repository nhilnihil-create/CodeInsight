#include<iostream>
using namespace std;

int main(){
 while(1){
  int w,h;
  cin >> h >> w;
  if(w==0&&h==0) break;

  for(int i=1;i<=h;++i){
   for(int j=1;j<=w;++j){
    if(j!=w&&i!=h&&j!=1&&i!=1) cout << ".";
    else cout << "#";
   }
  cout << endl;
  }
 cout << endl;
 }
 return 0;
}