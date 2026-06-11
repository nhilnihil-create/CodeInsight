#include<iostream>
 
using namespace std;
#define newl '\n'

void solve(){
  int n ;
  cin >> n;
  int flag = 0;
  while( n != 0){
    int q = n % 10;
    if(q == 7){
      flag = 1;
    }
    n /= 10;
  }
  if(flag == 0){
    cout<< "No" <<endl;
  }
  else{
    cout<< "Yes" <<endl;
  }

}


int main(){
  
  solve();

}