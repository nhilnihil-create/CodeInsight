#include <bits/stdc++.h>
using namespace std;

unsigned GetDigit(unsigned num){
    return to_string(num).length();
}

int main(void){
 
  int N,c = 0;
  cin >> N;
  for(int i=1;i<=N;i++){
      if(GetDigit(i) %2== 1) c++;
  }
  cout << c << endl;
}