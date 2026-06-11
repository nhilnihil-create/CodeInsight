#include<iostream>
#include<string>
using namespace std;
int main(){
  string a;
  cin >> a;
  if(a[0] == '7' || a[1] == '7' || a[2] == '7'){
    cout <<"Yes\n";
    return 0;
  }
  cout << "No\n";
}