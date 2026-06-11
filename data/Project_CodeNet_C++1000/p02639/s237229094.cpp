#include<iostream>
using namespace std;
int main(){
  int x[5],i,ans=0;
  for(i=0; i<5; i++){
    cin >> x[i];
    if(x[i]==0){
      ans=i+1;
    }
  }
  cout << ans << endl;
  return 0;

}
