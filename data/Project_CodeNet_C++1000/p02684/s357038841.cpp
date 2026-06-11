#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,s,t=1,cnt=0;
  int64_t k;
  cin >> n >> k;
  int a[n],b[(1<<25)];
  for(int i=1;i<=n;i++)cin >> a[i];
  while(k--){
    t=a[t];
    if(b[t])k%=cnt-b[t];
    b[t]=cnt++;
  }
  cout << t << endl;
}