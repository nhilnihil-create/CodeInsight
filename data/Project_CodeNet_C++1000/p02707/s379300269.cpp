#include<bits/stdc++.h>
using namespace std;
int main(){
  int64_t n;
  cin >> n;
  int64_t a,cnt[n];
  for(int64_t i=1;i<=n;i++)cnt[i]=0;
  while(cin >> a){
    cnt[a]++;
  }
  for(int64_t i=1;i<=n;i++){
    cout << cnt[i] << endl;
  }
}
