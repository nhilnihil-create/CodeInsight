#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N,X,ans=0,aaa=0;
  cin >> N >> X;
  for(int i=0; i<N; i++){
    int S;
    cin >> S;
    ans += S;
    if(ans <= X){
      aaa++;
    }
  }
  cout << aaa +1 << endl;
}
