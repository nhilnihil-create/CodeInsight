#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  int s;
  bool ok=false;
  for(int i=0;i<=n;i++){
    if(floor(i*1.08)==n){
      ok=true;
      s=i;
      break;
    }
  }
  if(ok)
    cout << s << endl;
  else
    cout << ":(" << endl;
  return 0;
}