#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (int)(n); ++i)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int n;
void dfs(string A){
  if(A.size()==n){
    cout<<A<<endl;
    return;
  }
  int ma=0;
  rep(i,A.size()){
    ma=max(ma,A.at(i)-'a');
  }
  rep(i,ma+2){
    char c='a'+i;
    A=A+c;
    dfs(A);
    A.pop_back();
  }
}
int main() {
  cin >> n;
  dfs("a");
}

