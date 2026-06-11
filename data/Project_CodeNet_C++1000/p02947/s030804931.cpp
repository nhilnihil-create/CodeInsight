#include<bits/stdc++.h>
#define rep(i,n) for (int i =0; i <(n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
  int N;
  cin >> N;
  string S;
  map<string,int>M;
  
  ll ans = 0;
  
  rep(i,N){
    cin >> S;
    sort(S.begin(),S.end());
    if(M.count(S))M[S]++;
    else M[S] = 0;
    ans += M[S];
    
  }
  
  cout << ans << endl;
}