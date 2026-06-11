#include<iostream>
using namespace std;

int main(){
  int N;
  cin >> N;
  int cnt = 1;
  while ( cnt * 1000 < N ){
    cnt++;
  }
  int ans = cnt * 1000 - N ;
  cout << ans ;
}
