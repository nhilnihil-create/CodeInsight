#include <iostream>
 using namespace std;
int main(){
  int N;
  cin >>N;
  int ans;
  ans = 0;
  for(int i=1;i<=N;i++){
    int p;
    cin >> p;
    if(i%2==1 && p%2==1){
      ans++;
    }
  }
  cout << ans<<endl;
}