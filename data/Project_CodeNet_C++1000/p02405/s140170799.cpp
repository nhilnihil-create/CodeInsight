#include<iostream>
using namespace std;

int main(){
   int h, w;
   while(1){
   cin >> h >> w;
   if( h == 0 && w == 0) break;
   for(int a = 0;a < h; a++){
    for(int b = 0; b < w; b++){
     if(a % 2 == 0){
      if( b % 2 == 0) cout << "#";
      else cout << ".";
     } else{
        if(b % 2  == 0) cout << ".";
        else cout << "#";
     }
    }
   cout << endl;
   }
  cout << endl;
 }
return 0;
}