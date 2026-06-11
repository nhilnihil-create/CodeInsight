#include<bits/stdc++.h>
using namespace std;

int main(){
  int N, D;
  cin >> N >> D;
  
  int tmp = N;
  int count = 0;
  for(int i = 0; i < 100; i++){
    count++;
    tmp = tmp - (2*D + 1);
    if(tmp <= 0) break;
  }
  cout << count << endl;
}

    