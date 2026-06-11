#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i <= (int)(n); i++)

int main(){
  int X, N;
  cin >> X >> N;
  set<int> p;
  int a;
  rep(i, N) {
    cin >> a;
    p.insert(a);
   }
  
  rep(i, 100){
   if(!p.count(X-i)){
    cout << X-i << endl;
     return 0;
   }else if(!p.count(X+i)){
    cout << X+i << endl; 
     return 0;
   }
  }         
}
