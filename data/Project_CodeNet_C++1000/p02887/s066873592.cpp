#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int n,count;
  string s;
  char w=' ';
  cin >> n>>s;
  count=n;
  rep(i,n){
    if(w==s[i]) count--;
    w=s[i];
  }
  cout << count<<endl;
}