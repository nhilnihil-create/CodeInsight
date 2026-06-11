#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
  int a;
  string b;
  cin >> a >> b;
  int ans=0;
  for(int i=0;i<a-2;i++){
    if(b.at(i)=='A'&&b.at(i+1)=='B'&&b.at(i+2)=='C')ans++;
  }
  cout << ans;
}
