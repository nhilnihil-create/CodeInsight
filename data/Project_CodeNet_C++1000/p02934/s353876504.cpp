#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  double su=0,b;
  for(int i=0;i<n;i++){
    cin >> b;
    su+=1/b;
  }
  cout << 1/su << endl;
  return 0;
}