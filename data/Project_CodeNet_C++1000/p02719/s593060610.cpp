#include<bits/stdc++.h>
using namespace std;
/*
n<|k-n|までwhileで計算量ダメそう(サンプル3)
10e18な時点でO(N)は不可

n==1 =>0 これ偽じゃんどうやって真であること証明したお前！？
n%k==0 =>0 これも証明済

*/
int main(){
  int64_t n,k;
  cin >> n >> k;
  if(k==1||n==k||n%k==0){
    cout << 0 << endl;
  }else {
  int64_t b=n/k+1;
    if(k<n){
      cout << min(abs(n-b*k),abs(n-b*k+k)) << endl;
    }else{
      cout << min(n,k-n) << endl;
    }
  }
  return 0;
}