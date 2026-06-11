#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  int j = n%10;
  if (j ==2 || j == 4 || j == 5 || j == 7 || j == 9){
    cout << "hon" << endl;
  }else if (j == 0 || j == 1 || j == 6 || j == 8){
    cout << "pon" << endl;
  }else{
    cout << "bon" << endl;
  }
}
