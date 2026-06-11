#include<bits/stdc++.h>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
using namespace std;
#define int long long

signed main(){
  int N;cin >> N;
  string S;cin >> S;
  int r = 0, g = 0, b = 0;
  for(int i = 0;i < S.length();i++){
    if(S[i] == 'R')r++;
    else if(S[i] == 'G')g++;
    else b++;
  }
  int hoge = 0;
  rep(i,N)rep(j,N){
    if(S[i] != S[j])if((i+j)%2 == 0 && S[i] != S[(i+j)/2] && S[j] != S[(i+j)/2]){hoge++;}
  }
  cout << r * g * b - hoge/2;
}

