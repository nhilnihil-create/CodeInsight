#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N,K;
  cin >> N >> K;
  
  for(int i=0;i<31;i++){
    if(pow(K,i+1)>N && N>=pow(K,i) ){
      cout << i + 1 << endl;
    }
  }
}