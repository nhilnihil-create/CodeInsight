#include <bits/stdc++.h>
using namespace std;
int main(){
  string n;cin>>n;
  bool ok = true;
  for(int i=0; i<3; i++){
    if(n[i]==n[i+1])ok=false;
  }
  cout<<(ok?"Good\n": "Bad\n");
}