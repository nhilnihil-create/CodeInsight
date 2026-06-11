#include<bits/stdc++.h>
using namespace std;
using ll = long long;


int main(){
  
  int N;
  cin >> N;
  int a;
  bool denied = false;
  for(int i = 0; i <N; i++){
    cin >> a;
    if(a % 2 == 0){
      if(a % 5 != 0 && a % 3 != 0)denied = true;
    }
  }
  if(denied) cout << "DENIED" << endl;
  else cout << "APPROVED" << endl;
}