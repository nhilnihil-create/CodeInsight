#include<bits/stdc++.h>
using namespace std;
long attack(long h){
  if(h ==1)
    return 1;
  else
    return  2 * attack(h/2) + 1;    
}
int main(){
  long h; cin >> h;
  cout << attack(h);
}