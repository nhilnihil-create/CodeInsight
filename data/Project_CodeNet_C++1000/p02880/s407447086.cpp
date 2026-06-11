#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using ll = long long;
using namespace std;

int main(){
  int a;
  cin>>a;
  rep(i,9){
    if(a%(i+1)==0&&a/(i+1)<=9){
      cout<<"Yes"<<endl;
      return 0;
    }
  }
  cout<<"No"<<endl;
}