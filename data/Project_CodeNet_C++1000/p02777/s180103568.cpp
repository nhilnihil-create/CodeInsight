#include<bits/stdc++.h>
using namespace std;

int main(){
  string s, t, u;
  int a, b;
  cin >>s>>t>>a>>b>>u;
  if(s == u){
  	cout << a-1 << endl;
  }
  else{
  	cout<< a << endl;
  }
  if(t == u){
  	cout << b-1 << endl;
  }
  else{
  	cout<< b << endl;
  }
}
