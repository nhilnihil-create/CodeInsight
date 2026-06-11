#include<bits/stdc++.h>
using namespace std;
int main(){
  int a,b;
  cin >> a  >> b;
  for(int i=1;;i++){
    int a1=i*0.08;
    int b1=i*0.1;
    if(a1==a && b1==b){
      cout << i << endl;
      break;
    }
    if(a1>a && b1>b){
      cout << -1  << endl;
      break;
    }
  }
}
