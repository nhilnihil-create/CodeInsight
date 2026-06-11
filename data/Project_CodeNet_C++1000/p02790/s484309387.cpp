#include<bits/stdc++.h>
using namespace std;

int main(){
  int a,b,l,h;
  cin>> a >> b;
  l=min(a,b); h=max(a,b);
  for(int i=0; i<h; i++){
    cout<< l;
  }
  cout<<endl;
}