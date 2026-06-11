#include<iostream>
using namespace std;

int main(){
  long N;
  cin >> N;
  
  long ans=0;
  for (long i=1; i<=N; i++){
    if ((i%3)*(i%5) != 0){
      ans += i;
    }
  }
  
  cout << ans << endl;
  
  return 0;
}
