#include <bits/stdc++.h>

using namespace std;

int N;
int ans=0;

void input(){
  cin >> N;
}

void solve(){
  for(int i=1;i<=N;i++){
    int tmp=i;
    int keta=0;
    while(tmp>0){
      tmp=tmp/10;
      keta++;
    }
    if(keta%2==1){
      ans++;
    }
  }
}

int main(){
  input();
  solve();
  cout << ans << endl;
  return 0;
}
