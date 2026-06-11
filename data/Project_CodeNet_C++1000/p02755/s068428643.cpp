#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++) 
#define all(v) begin(v),end(v)
using ll = long long;

int main() {
  int a,b;cin>>a>>b;
  rep(i,10000){
    int A=i*8/100,B=i*10/100;
    if(a==A&&b==B){
      cout<<i<<endl;
      return 0;
    }
  }
  cout<<-1<<endl;
}