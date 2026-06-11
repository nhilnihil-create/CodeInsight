#include <bits/stdc++.h>
using namespace std;

int main(){
  
  int a,b,c;
  cin >>a>>b>>c;
  if(b/a==c/a&&b%a!=0){
    cout << "NG"<<endl;
  }
  else{
    cout <<"OK" <<endl;
  }
}