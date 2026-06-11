#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i ,n) for(int i = 0; i < (int)(n); i++)

int main(){
  int N,D;
  cin >> N >> D;
  int counter = 0;
  for(int i=0; i<N; i=i+2*D+1){
    counter++;
  }
  cout << counter << endl;
}