#include <bits/stdc++.h>
using namespace std;

int main(){
  unsigned long long int N,M;
  cin >> N >> M;
  if((N+M)%2==0){
    cout << (N+M)/2 << endl;
  }
  else{
    cout << "IMPOSSIBLE" << endl;
  }
}