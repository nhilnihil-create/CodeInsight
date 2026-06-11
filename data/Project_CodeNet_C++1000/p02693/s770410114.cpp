#include<iostream>
using namespace std;

int main(){
  int K, A, B;
  cin >> K >> A >> B;
  bool flag = false;
  
  for(int i=A;i<=B;i++){
    if(i%K == 0){
      flag = true;
    }
  }
  
  if(flag) cout << "OK" << endl;
  else cout << "NG" << endl;
}
