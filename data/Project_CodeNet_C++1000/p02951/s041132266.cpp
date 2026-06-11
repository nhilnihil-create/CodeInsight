#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i ,n) for(int i = 0; i < (int)(n); i++)

int main(){
  int A,B,C;
  cin >> A >> B >> C;
  
  A -= B;
  
  if(A<=0) cout << C << endl;
  else if(A >= C) cout << 0 << endl;
  else cout << C- A << endl;
}
