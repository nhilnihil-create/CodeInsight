#include<bits/stdc++.h>
using namespace std;

int main(){
  int n,a;
  cin >> n >> a;
  int su=0,b; 
  for(int i=0;i<a;i++){
    cin >> b;
    su+=b;
  }
  cout << (n<su?-1:n-su) << endl;
  return 0;
}