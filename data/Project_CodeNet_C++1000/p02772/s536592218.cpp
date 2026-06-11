#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  cin >> n;
  
  int a[n];
  int ans = 0;
  for(int i = 0; i < n; i++){
    cin >> a[i];
    if(a[i] % 2 == 0){
      ans++;
    }
  }
  
  for(int i = 0; i < n; i++){
    if( (a[i] % 2 == 0) && ((a[i] % 3 == 0) || (a[i] % 5 == 0)) ){
      ans--;
    }
  }
  
  if(ans == 0){
    cout << "APPROVED" << endl;
  }else{
    cout << "DENIED" << endl;
  }
}