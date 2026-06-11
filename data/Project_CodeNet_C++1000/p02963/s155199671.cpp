#include <bits/stdc++.h>
using namespace std;

int main(){
  long long S; cin >> S;
  long long b=S/1000000000,c=S%1000000000;
  if(b==0){
    cout << "0 0 1 0 0 " << S << endl;
  }else if(c==0){
    cout << "0 0 0 1000000000 " << b << " 0" << endl;
  }else{
    cout << "0 " << c << " " << b << " 0 " << b+1 << " 1000000000" << endl;
  }
}