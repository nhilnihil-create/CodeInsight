#include <iostream>
#include <string>
using namespace std;
int main(){
  string n;
  cin >> n;
  if(n[n.size()-1]=='3'){
    cout << "bon";
  }else if(n[n.size()-1]=='0' || n[n.size()-1]=='1' || n[n.size()-1]=='6' || n[n.size()-1]=='8'){
    cout << "pon";
  }else{
    cout << "hon";
  }
}