#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
typedef long long ll;
int main() {
  int a;
  cin>>a;
  rep(i,9){
    if(a%(i+1)==0 && a/(i+1)<10){
      cout<<"Yes";
      return 0;
    }
  }
  cout<<"No";
}