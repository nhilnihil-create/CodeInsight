#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int) n; i++)
using ll = long long;
template <class T>
using vt = vector<T>;
using vvi = vector<vector<int>>;

void svtr(vector<int> &a){
  sort(a.begin(),a.end());
  reverse(a.begin(),a.end());
}

int main() {
  string s;
  cin >> s;

  if(s.size()%2==1){
    cout << "No";
    return 0;
  }

  rep(j,s.size()){
    if(s[j]=='h' && j%2==0)
      continue;
    if(s[j]=='i' && j%2==1)
      continue;
    else{
      cout << "No";
      return 0;
    }
  }

  cout << "Yes";
  return 0;
}
