#include<iostream>
using namespace std;

int main(){
  int N,D;  cin >> N >> D;
  int ans = 0;
  while(N>0){
    N -= 2*D+1;
    ans++;
  }
  cout << ans << endl;
}
