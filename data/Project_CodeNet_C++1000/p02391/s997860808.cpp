#include<iostream>

using namespace std;

#define rep(i,n) for(i=0;i<(n);i++)
#define For(i,a,b) for(i=(a);i<(b);i++)

int main(){
  int i,j,k;
  int a,b;

  cin >> a >> b;
  if(a<b) cout << "a < b";
  else if(a>b) cout << "a > b";
  else cout << "a == b";
  cout << endl;
  
  return 0;
}