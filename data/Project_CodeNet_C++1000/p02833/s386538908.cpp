#include <iostream>

using namespace std;

int main(){
  long long n;
  cin >> n;
  if(n%2==1){
    cout << 0;
  }else{
    long long x=n/10, y=0;
    while(x!=0){
      y+=x;
      x/=5;
    }
    cout << y;
  }
}