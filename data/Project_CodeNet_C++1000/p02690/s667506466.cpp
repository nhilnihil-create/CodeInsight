#include<bits/stdc++.h>
using namespace std;
int main(){
  int x;
  cin >> x;
  bool t=false;
  for(int64_t b=-150;b<150;b++){
      for(int64_t a=-150;a<150;a++){
        if((a-b)*((a-b)*(a-b)*(a-b)*(a-b)+5*a*b*((a-b)*(a-b)+a*b))==x){
          cout << a << " " << b << endl;
          t=true;
          return 0;
        }
      }
  }
}
  
