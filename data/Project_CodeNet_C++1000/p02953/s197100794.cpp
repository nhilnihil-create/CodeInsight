#include <bits/stdc++.h>
using namespace std;

int main() {
  
  int n,h,next;
  cin >> n >> h;
  
  int hantei = 1;
  
  for ( int i = 1; i < n; i++){
    cin >> next;
    if ( h == next ){
      h = next;
      continue;
    }else if ( h + 1 <= next ){
      h = next - 1;
      continue;
    }else{
      hantei = 0;
      break;
    }
  }
  
  if ( hantei ){
    cout << "Yes" << endl;
  }else{
    cout << "No" <<endl;
  }
  
}
