#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,h,a;
  cin >> n >> h;
  for(int i=0;i<h;i++){
    cin >> a;
    n-=a;
  }
  if(n>0)cout << "No" << endl;
  else cout << "Yes" << endl;
}
