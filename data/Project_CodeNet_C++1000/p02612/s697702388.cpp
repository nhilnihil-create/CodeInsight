#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;
  cin >> N;
  int num=0;
  for(int i=0;i<10;i++){
    if(num<N) num+=1000;
  }
  cout << num-N << endl;
}