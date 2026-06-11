#include <bits/stdc++.h>
using namespace std;

int main() {
  int k;
  cin >> k;

  if(k%2==0){
    cout << -1 << endl;
    return 0;
  }

  // long long tmp=0;
  // long long hoge=1;
  // long cnt=0;
  // while(true){
  //   tmp += hoge * 7;
  //   hoge *= 10;
  //   cnt++;
  //   cout << tmp%k << endl;
  //   if(tmp%k==0){
  //     break;
  //   }
    
  // }

  int cnt = 1;
  long long tmp = 7%k;
  if(tmp==0){
    cout << cnt << endl;
    return 0;
  }
  for(int i=0;i<k;i++){
    tmp = 10*tmp + 7;
    tmp = tmp%k;
    cnt++;
    if(tmp==0){
      cout << cnt << endl;
      return 0;
    }
  }

  cout << -1 << endl;
  return 0;
}
