#include <bits/stdc++.h>
using namespace std;

int main(){
  int n; cin >> n;
  long long k; cin >> k;
  vector<int> a(n);
  for(int i = 0 ; i<n ; i++){
    cin >> a[i];
  }
  vector<bool> visit(n+1,false);
  int now = 1;
  long long leng = 0;
  while(true){
    if(visit[now]) break;
    visit[now] = true;
    now = a[now-1];
    leng++;
  }
  
  int p = now;
  long long loop = 0;
  while(true){
    p = a[p-1];
    loop++;
    if(p == now) break;
  }
  long long d = leng - loop;
  long long cnt = 0;
  if(k <= d){
    cnt = k;
  }else{
    cnt = (k-d)%loop + d;
  }
  now = 1;
  for(long long i = 0 ; i < cnt; i++){
    now = a[now-1];
  }
  cout << now << endl;
}
  
  
  
