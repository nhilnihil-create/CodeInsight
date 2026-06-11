#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  bool t=true;
  if(n!=0){
  for(int i=1;i<=9;i++){
    for(int j=1;j<=9;j++){
      if((double)n/i==j){
        t=false;
        cout << "Yes" << endl;
        break;
      }
    }
    if(t==false)break;
  }
  if(t)cout << "No" << endl;
  }else cout << "No" << endl;
}
