#include <bits/stdc++.h>
using namespace std;

int main(){
  int cnt = 0;
  int N;cin >> N;
  for(int i=0;i<N;i++){
    int a;cin >> a;
    if(i%2==0&&a%2==1){
      cnt ++;
    }
  }
  cout << cnt << endl;
}