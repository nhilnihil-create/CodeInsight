#include<bits/stdc++.h>
using namespace std;
int64_t cnt=0;
int64_t f(int64_t h){
  if(h==1)return 1;
  if(h>1)return 2*f(h/2)+1;
}
  
int main(){
  int64_t h;
  cin >> h;
  cout << f(h) << endl;
}
  