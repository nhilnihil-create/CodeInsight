#include <bits/stdc++.h>
#define int long long
using namespace std;

int N;
void dfs(char c, vector<char> &S){
  if( S.size() == N ){
    for( int i = 0; i < N; i++ ) cout << S.at(i);
    cout << endl;
    return;
  }else{
    for( char h = 'a'; h <= c+1; h++ ){
      S.push_back(h);
      dfs(max(c, h), S);
      S.pop_back();
    }
  }
}
signed main() {
  cin >> N;
  vector<char> S;
  S.push_back('a');
  dfs('a', S);
}