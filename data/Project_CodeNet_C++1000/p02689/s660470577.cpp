#include<bits/stdc++.h>
using namespace std;

int main(){
  int n,m;
  cin >> n >> m;
  vector<long long> h(n);
  bool p[n];
  int ans = 0;
  for(int i = 0; i < n; i++){
    p[i] = true;
  }
  for(int i = 0; i < n; i++){
    cin >> h[i];
  }
  for(int i = 0; i < m; i++){
    int a,b;
    cin >> a >> b;
    if(h[a-1] > h[b-1]) p[b-1] = false;
    else if(h[a-1] < h[b-1]) p[a-1] = false;
    else if(h[a-1] == h[b-1]) {p[a-1] = false; p[b-1] = false;}
  }
  for(int i = 0; i < n; i++){
    if(p[i] == true) ans++;
  }
  cout << ans << endl;
}