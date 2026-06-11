#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,count=0;
  cin >> N;
  for(int i=1;i<(N+1)/2;i++){
    count++;
  }
  cout << count << endl;
}