#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,k,cnt=0;
  cin >> n >> k;
  while(n>0){
    int Q=n/k;
    n=Q;
    cnt++;
  }
  cout << cnt << endl;
}
