#include<bits/stdc++.h>
using namespace std;

int main(){
  int h,n;
  cin >> h >> n;
  int su=0,b;
  for(int i=0;i<n;i++){
    cin >> b;
    su+=b;
  }
  cout << (h>su?"No":"Yes") << endl;
  return 0;
}