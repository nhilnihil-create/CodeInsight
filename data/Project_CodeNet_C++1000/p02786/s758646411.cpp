#include <bits/stdc++.h>
using namespace std;

int main(){
  long long h;	cin >> h;
  long long c=1;
  long long ans=0;
  while(h>0){
    h/=2;
    ans+=c;
    c*=2;
  }
  cout << ans;
}