#include <bits/stdc++.h>
using namespace std;
 
int main(){
  int n;
  int i;
  cin >> n;
  int num[n];
  for(i = 0; i < n; i++){
	cin >> num[i];
  }
  int f1 = 0;
  for(i = 0; i < n; i++){
    if(num[i] % 2 == 0 && num[i] % 3 != 0 && num[i] % 5 != 0){
          f1++;
    }
  }
  if(f1 == 0){
    cout << "APPROVED" << endl;
  }
  else if(f1 != 0){
    cout << "DENIED" << endl;
  }
}