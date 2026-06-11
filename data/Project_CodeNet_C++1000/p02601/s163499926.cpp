#include <bits/stdc++.h>
using namespace std;
int main() {
  int a,b,c; cin>>a>>b>>c;
  int k; cin>>k;
  int n=0;
  while(a>=b){
    b*=2;
    n++;
  }
  while(b>=c){
    c*=2;
    n++;
  }
  cout<<((n>k)?"No":"Yes")<<endl;
}

