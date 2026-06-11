#include<iostream>
#include<string>
using namespace std;
 
int main(){
  int n;
  string ans;
  cin >> n;
  for(int i = 1;i <= 9;i++){
    for(int j = 1;j <= 9;j++){
      if(i * j == n){
        ans = "Yes";
        break;
      }
    }
  }
  if(ans != "Yes"){
    ans = "No";
  }
  cout << ans;
}