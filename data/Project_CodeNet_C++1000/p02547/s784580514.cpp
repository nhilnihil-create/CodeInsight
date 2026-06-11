#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;
  cin >> N;
  int count = 0;
  for(int i = 0; i<N; i++){
    int a, b;
    cin >> a >> b;
    if(a==b){
      count++;
    }
    else{
      count = 0;
    }
    if(count==3){
      cout << "Yes" << endl;
      break;
    }
    if(i==N-1){
      cout << "No" << endl;
    }
  }
}