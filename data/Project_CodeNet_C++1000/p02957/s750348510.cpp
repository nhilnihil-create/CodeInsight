#include<bits/stdc++.h>
using namespace std;
int main(){
  int a,b;
  cin >> a  >> b;
  for(int i=0;i<=1000000000;i++){
    if(abs(i-a)==abs(i-b)){
      cout << i << endl;
      return 0;
    }
  }
  cout << "IMPOSSIBLE" << endl;
  return 0;
}