#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  bool t=true;
  cin >> n;
  for(int i=0;i<n;i++){
    int a;
    cin >> a;
    if(a%2==0){
      if(a%3==0 || a%5==0)continue;
      else{
        cout << "DENIED" << endl;
        t=false;
        break;
      }
    }
  }
  if(t)cout << "APPROVED" << endl;
}