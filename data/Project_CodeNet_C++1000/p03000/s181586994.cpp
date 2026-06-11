 #include <bits/stdc++.h>
using namespace std;

int main() {
 int n, x; cin >> n>>x;
  vector<int> l(n);
  for(int i = 0; i<n;i++) cin >> l[i];
  int ans = 1;
  int d = 0;
  for(int i = 0;i<n;i++){
    if(d+l[i]<=x){
      ans++;
      d = d+l[i];
    } else {
      d = d+l[i];
    }
  }
  cout << ans << endl;
}

