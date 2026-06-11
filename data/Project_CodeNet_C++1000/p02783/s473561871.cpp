#include<iostream>
using namespace std;

int main(){
  int h,a,n;
  cin >> h >> a;
  if(h%a==0){
    n = h/a;
  }else{
    n = h/a+1;
  }
  cout << n;
}