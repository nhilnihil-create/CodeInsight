#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
using ll = long long;
const ll INF =1001001001;

int main(){
  int A,B;
  cin >> A >> B ;
  int abottom;
  if(A%2==0){
    abottom = A*25/2;
  }else abottom = A*25/2+1;
  int atop;
  if(A%2==0){
    atop = (A+1)*25/2+1;
  }else atop = (A+1)*25/2;
  int bbottom=B*10;
  int btop = (B+1)*10;
  for(int i= abottom;i<atop;i++){
    for(int j=bbottom;j<btop;j++){
      if(i==j){
        cout << i << endl;
        return 0;
      }
    }
  }
  cout << -1 << endl;
  return 0;
}
