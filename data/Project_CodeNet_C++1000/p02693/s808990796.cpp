#include<bits/stdc++.h>
using namespace std;
int main(){
  int k,a,b;
  cin >> k;
  cin >> a >> b;
  int flag = 0;
  for (int i = a; i <= b; i++){
    if (i%k==0){
      flag++;
      cout << "OK" << endl;
      break;
    }
  }
  if (flag == 0){
    cout << "NG" << endl;
  }
}
