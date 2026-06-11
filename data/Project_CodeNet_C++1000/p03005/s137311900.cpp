#include<bits/stdc++.h>
using namespace std;

int main(){
  int n , k;
  cin >> n >> k;

  if(k == 1){
    cout  << 0 <<endl;
  }
  else{
    int judg;
    judg = n - k;
    cout << judg <<endl;
  }
}