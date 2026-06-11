#include <bits/stdc++.h>
using namespace std;
 
int main(){
  int n,r;
  cin >> n >> r;
  int ans;
  if(n<10){
    ans=r+100*(10-n);
  }
  else{
    ans=r;
  }
  cout << ans << endl;
}
