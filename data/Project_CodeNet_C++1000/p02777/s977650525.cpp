#include<iostream>
#include<string>
using namespace std;
int main(){
  int a , b;
  string s, t, u;
  cin >> s >> t;
  cin >> a >> b;
  cin >> u;
  if(s == u){
    a--;
    cout << a << " " << b <<"\n";
    return 0;
  }
  if(t == u){
    b--;
    cout << a  << " " << b <<"\n";
    return 0;
  }
}