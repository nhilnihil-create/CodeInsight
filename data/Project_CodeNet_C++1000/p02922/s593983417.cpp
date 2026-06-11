#include<iostream>
using namespace std;

int main(){
  int a,b; cin >> a >>b;
  int outlet = 1;
  int cnt = 0;
  for(int i = 1; ;i++){
    if(outlet >= b){
      cout << cnt;
      return 0;
    }
    cnt++;
    outlet += a-1;
  }
}
