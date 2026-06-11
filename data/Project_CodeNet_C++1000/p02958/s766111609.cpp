#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N, P;
  int count=0;
  cin >> N;
  for(int i=1;i<=N;i++){
    cin>>P;
    if(P!=i){
      count+=1;
    }
  }
  if(count<3){
    cout << "YES";
  }else{
    cout << "NO";
  }
  return 0;
}