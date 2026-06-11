#include <string>
#include <iostream>

using namespace std;

int main(){
  string a;
  string b;
  int n=0;

  cin >> a;
  cin >>b;
  for(unsigned int i = 0; i < a.size(); ++i){
    if(a[i]==b[i])continue;
    n++;
  }
  cout << n <<endl;
  return 0;
}