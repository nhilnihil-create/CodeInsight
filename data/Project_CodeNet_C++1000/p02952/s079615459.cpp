#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  int c = 0;

  for (int i = 1;i <= N;i++){
    int s = i;
      int n = 0;
    while (s!=0){
      s /= 10;
      n++;
    }
    if ((n % 2) == 1){
      c++;
    } 
  }
  cout << c << endl;
}