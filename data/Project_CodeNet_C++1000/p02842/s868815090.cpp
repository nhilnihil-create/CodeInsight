#include<bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  bool a=false;
  for(int i=1;i<N+1;i++){
    int c=i*1.08;
    if(c==N){
      a=true;
      cout << i << endl;
    }
  }
  if(!a){
    cout << ":(" << endl;
  }
}