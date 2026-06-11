#include<iostream>
using namespace std;

int main(){
  int r,g,b;
  int k;
  cin >> r >> g >> b;
  cin >> k;
  
  for(int i=0; i<k; i++){
   if(g <= r){
     g *= 2;
   }else if(b <= g){
	 b *= 2;
   }
  }
 if(b > g && g > r){
   cout << "Yes" << endl;
 }else{
   cout << "No" << endl;
 }
  return 0;
}