#include<bits/stdc++.h>
using namespace std;

int main(){
  int a[4],i;
  for(i=0;i<3;i++){
    cin >> a[i];
  }
  sort(a,a+3);
  for(i=0;i<3;i++){
    cout << a[i];
    if(i<2){
      cout << " ";
    }
  }
  cout << '\n';
  return 0;
}
  

