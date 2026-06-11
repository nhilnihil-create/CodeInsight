#include <bits/stdc++.h>
using namespace std;

int main() {
  string a;
  int A,cou=0;
  cin>>A>>a;
  A-=2;
  for(int i=0;i<A;i++){
    if(a[i]=='A'&&a[i+1]=='B'&&a[i+2]=='C'){
      cou++;
    }
  }
  cout<<cou<<endl;
}