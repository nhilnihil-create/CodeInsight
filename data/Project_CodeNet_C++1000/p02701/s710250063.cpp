#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)

int main(){
  int n;
  cin >> n;
  vector<string> s(n);
  int same = 0;
  rep(i,n){
    cin >> s[i];
  }
  sort(s.begin(),s.end());
  s.erase(unique(s.begin(),s.end()),s.end());
  int size;
  size = s.size();
  cout << size << endl;
  return 0;
}
