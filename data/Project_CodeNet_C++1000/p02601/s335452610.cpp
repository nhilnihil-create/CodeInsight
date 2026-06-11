#include <cmath>
#include <iostream>
//#include <string>
using namespace std;

int main(){
  int A,B,C,K;
  string ans="No";
  cin >> A >> B >> C;
  cin >> K;
  for(int i=0;i<=K;i++){
    for(int j=0;j<=K-i;j++){
      if(A<B*pow(2,i)&&B*pow(2,i)<C*pow(2,j)) ans="Yes";
    }
  }
  cout << ans << endl;
}