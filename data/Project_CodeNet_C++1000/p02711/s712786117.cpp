#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;	cin >> n;
  for(int i=0;i<3;i++){
    if(n%10==7){
      cout << "Yes";
      return 0;
    }
    n/=10;
  }
  cout << "No";
}