
#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int n;
  cin >> n;
  int p;
  int c = 0;
  for(int i = 1; i <= n; i++){
    cin>>p;
    if(i != p){
      c++;
    }
  }
  if(c >= 3){
    cout<<"NO"<<endl;
  }else{
    cout<<"YES"<<endl;
  }
}
