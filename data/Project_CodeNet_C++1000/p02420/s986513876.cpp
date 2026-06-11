#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>

using namespace std;
typedef long long ll;

int main(){
  int n, m;
  string a, b, c;
  while(true){
    cin>>a;
    if(a=="-"){
      break;
    }
    cin>>n;
    for(int i=0; i<n; ++i){
      cin>>m;
      b = a.substr(0, m);
      c = a.substr(m);
      a = c + b;
    }
    cout<<a<<endl;
  }
}