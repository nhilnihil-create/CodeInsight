#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;	cin >> n;
  string s="APPROVED";

  for(int i=0;i<n;i++){
    int x;	cin >> x;
    if(x%2==0){
      if(!(x%3==0||x%5==0)){
        s="DENIED";
      }
    }
  }
  cout << s;
}