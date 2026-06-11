#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int x;
  cin>>x;
  int min_x,max_x;
  min_x=x/100*100;
  max_x=x/100*105;
  if(min_x<=x&&x<=max_x){
    cout<<1<<endl;
  }else{
    cout<<0<<endl;
  }
}