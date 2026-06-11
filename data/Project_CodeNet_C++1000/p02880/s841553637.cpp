#include<bits/stdc++.h>
using namespace std;
int main(){
  int N;
  cin >> N;
  
  bool yn=false;
  
  for(int i=1;i<=9;i++){
    bool fin=false;
    for(int j=1;j<=9;j++){
      if(i*j==N){
        yn=true;
        fin=true;
        break;
      }
    }
    if(fin==true)break;
  }
  
  if(yn==true)cout << "Yes" << endl;
  else cout << "No" <<endl;
}
        