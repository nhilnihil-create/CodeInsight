#include<bits/stdc++.h>
using namespace std;

int main(){
  int a,b,c,k;
  cin >> a >> b >> c >> k;
  while(b <= a && k > 0){
    b *= 2;
    k--;
  }
  while(c <= b && k > 0){
    c *= 2;
    k--;
  }
  if(a < b && b < c){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
}