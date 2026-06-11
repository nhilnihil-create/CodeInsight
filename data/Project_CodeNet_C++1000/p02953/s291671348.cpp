#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  int m=0,h,i;
  for(i=0;i<n;i++){
    cin >> h;
    if(h<=m-2){
      cout << "No" << endl;
      return 0;
    }
    m=max(m,h);
  }
  
  cout << "Yes" << endl;
}