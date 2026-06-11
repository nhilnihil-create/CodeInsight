#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,s,n) for(int i = s; i < (int)(n); i++)

int n;
void dfs(string s,int m){
  int size = s.size();
  if(size == n){
    cout << s << endl;
    return;
  }
  int p = m+2;
  rep(i,0,p){
    char a = 'a'+i;
    string v = s+a;
    if(i == m+1) m++;
    dfs(v,m);
  }
}
  
int main() {
  cin >> n;
  dfs("a",0);
}