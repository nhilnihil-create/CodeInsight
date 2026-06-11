#include<iostream>
#include<algorithm>
using namespace std;

int count(int n) {
  int i, count=0;
  
  for(i=n; i>0; i/=10) {
    count++;
  }
  
  return count;
  
}

int main() {
  int i,N,sum=0;
  
  cin >> N;
  
  for(i=1; i<=N; i++) {
    if(count(i)%2 == 1) sum++;
  }
  
  cout << sum << endl;
  
  return 0;
}