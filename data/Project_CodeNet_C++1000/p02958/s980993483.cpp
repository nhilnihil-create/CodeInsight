#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  vector<int> b(n);
  for(int i = 0; i < n; i++) cin >> a[i];
  for(int i = 0; i < n; i++) b[i] = i + 1;
  int cnt = 0;
  for(int i = 0; i < n; i++)
    if(a[i] != b[i]) cnt++;
  cout << (cnt <= 2 ? "YES" : "NO") << endl;
}