#include <bits/stdc++.h>
using namespace std;

bool digitsodd(int x){
  int count=0;
  while(x>0){
    x/=10;
    count++;
  }
  return count%2!=0;
}

int main() {
  int N;
  cin >> N;
  int count=0;
  for(int i=1;i<=N;i++){
    if(digitsodd(i)) count++;
  }
  cout << count << endl;
}
