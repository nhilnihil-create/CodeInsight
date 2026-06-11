#include<bits/stdc++.h>
#define rep(i,n) for (int i =0; i <(n); i++)
using namespace std;
using ll = long long;
using P = pair<string,int>;

int main(){
  int N;
  string S;
  cin >> N >> S;
  int ans = 1;
  for(int i = 1; i<N; i++){
    if(S.at(i) != S.at(i-1))ans++;
  }
  cout << ans << endl;
  
}