#include <bits/stdc++.h>
using namespace std;

int main(){
  int m,d,m2,d2;
  cin >> m >> d >> m2 >> d2;
  
  if(m!=m2&&(d+1)!=d2){
    cout << "1";
  }else{
    cout << "0";
  }
}