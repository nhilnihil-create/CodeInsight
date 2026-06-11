#include <bits/stdc++.h>
using namespace std;
int main(){
  long long N; 
  cin >> N;
  for(int i=0;i<50001;i++){
    if((i+1)*27/25 == N){
      cout << i+1 << endl;
      return 0;
    }
  }
  cout << ":(" << endl;
}
